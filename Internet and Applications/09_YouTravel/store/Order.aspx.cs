using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _09_YouTravel_store_Order : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        latitudeHiddenField.Value = Session["latitude"].ToString();
        longitudeHiddenField.Value = Session["longitude"].ToString();

        userLabel.Text = Session["userName"].ToString();
        placeLabel.Text = Session["place"].ToString();
        youtubeIdHiddenField.Value = Session["youtubeId"].ToString();

        priceLabel.Text = string.Format("{0:N0}", Convert.ToInt32(Session["price"]));
        daysLabel.Text = Session["days"].ToString();
        totalLabel.Text = string.Format("{0:N0}", Convert.ToInt32(Session["totalHidden"]));

        tripDateLabel.Text = Session["tripDate"].ToString();
    }
    protected void orderButton_Click(object sender, EventArgs e)
    {
        tripSqlDataSource.Insert();

        string senderName = "YouTrabel";
        string senderAddress = "jerry25418500@gmail.com";
        string receiverName = userLabel.Text;
        string receiverAddress = "jerry25418500@gmail.com";
        string subject = placeLabel.Text + " " + tripDateLabel.Text;
        string message = receiverName + ":<br>銘謝惠顧！祝旅途愉快！<br>地圖資訊請參考。<br>" + senderName + "敬上<br>";

        string tripMap = string.Format("<img src='http://maps.googleapis.com/maps/api/staticmap?"
            + "center={0},{1}"
            + "&zoom=15"
            + "&size=360x240"
            + "&maptype=roadmap"
            + "&markers=color:red%7C{0},{1}"
            + "&sensor=false'/>", latitudeHiddenField.Value, longitudeHiddenField.Value);

        MailServiceReference.MailData mail = new MailServiceReference.MailData();
        mail.senderAddress = senderAddress;
        mail.receiverAddress = receiverAddress;
        mail.subject = subject;
        mail.message = message + tripMap;

        MailServiceReference.MailServiceClient mailService = new MailServiceReference.MailServiceClient();
        mailService.sendMail(mail);

        Response.Redirect("tripList.aspx");
    }

}