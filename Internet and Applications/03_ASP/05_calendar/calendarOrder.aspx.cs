using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _03_ASP_05_calendar_calendarOrder : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        userLabel.Text = Session["user"].ToString();
        placeLabel.Text = Session["place"].ToString();
        string youtubeId = Session["youtubeId"].ToString();
        youtubeIdHiddenField.Value = youtubeId;


        tripDateLabel.Text = Session["tripDate"].ToString();
    }
    protected void youtubeIdHiddenField_ValueChanged(object sender, EventArgs e)
    {

    }
}