using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mail;
using System.Net.Mime;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

// 注意: 您可以使用 [重構] 功能表上的 [重新命名] 命令同時變更程式碼、svc 和組態檔中的類別名稱 "MailService"。
public class MailService : IMailService
{
    public void sendMail(MailData mailData)
    {
        string smtpServer = "smtp.gmail.com";
        int smtpPort = 587;

        string userName = "jerry25418500@gmail.com";
        string password = "qwe123qaz125";

        MailMessage mailMessage = new MailMessage();

        mailMessage.From = new MailAddress(mailData.senderAddress);
        mailMessage.To.Add(new MailAddress(mailData.receiverAddress));

        mailMessage.Subject = mailData.subject;
        mailMessage.SubjectEncoding = Encoding.UTF8;

        ContentType mineType = new ContentType("text/html");
        AlternateView mineTypeMessage = AlternateView.CreateAlternateViewFromString(mailData.message, mineType);
        mailMessage.AlternateViews.Add(mineTypeMessage);

        SmtpClient smtpClient = new SmtpClient(smtpServer, smtpPort);
        smtpClient.Credentials = new System.Net.NetworkCredential(userName, password);
        smtpClient.EnableSsl = true;

        smtpClient.Send(mailMessage);
    }
}
public class MailData
{
    public string receiverName;
    public string receiverAddress;
    public string senderName;
    public string senderAddress;
    public string subject;
    public string message;
}
