using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _03_ASP_02_youtube_youtubeTrip: System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void goButton_Click(object sender, EventArgs e)
    {
        Session["user"] = userTextBox.Text;
        Session["youtubeId"] = placeRadioButtonList.SelectedItem.Value; 
        Session["place"] = placeRadioButtonList.SelectedItem.Text;

        Response.Redirect("youtubeOrder.aspx");
    }
}