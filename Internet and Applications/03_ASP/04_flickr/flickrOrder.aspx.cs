using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _03_ASP_04_flickr_flickrOrder : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        userLabel.Text = Session["user"].ToString();
        placeLabel.Text = Session["place"].ToString();
        string youtubeId = Session["youtubeId"].ToString();
        youtubeIdHiddenField.Value = youtubeId;
    }
    protected void youtubeIdHiddenField_ValueChanged(object sender, EventArgs e)
    {

    }
}