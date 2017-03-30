using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _10_Facebook_mail_simpleMail : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        senderNameTextBox.Text = Session["userName"].ToString();
        senderAddressTextBox.Text = Session["email"].ToString();
    }
    protected void TextBox1_TextChanged(object sender, EventArgs e)
    {

    }
    protected void sendButton_Click(object sender, EventArgs e)
    {
        MailServiceReference.MailData mailData = new MailServiceReference.MailData();

        mailData.senderName = senderNameTextBox.Text;
        mailData.senderAddress = senderAddressTextBox.Text;
        mailData.receiverName = receiverNameTextBox.Text;
        mailData.receiverAddress = receiverAddressTextBox.Text;
        mailData.subject = subjectTextBox.Text;
        mailData.message = receiverNameTextBox.Text + ":<br><br>" + messageTextBox.Text + "<br><br>" + senderNameTextBox.Text;
        MailServiceReference.MailServiceClient mailService = new MailServiceReference.MailServiceClient();

        mailService.sendMail(mailData);
        Response.Redirect("simpleMail.aspx");
    }
}