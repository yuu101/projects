using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _03_ASP_01_simple_simpleOrder : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        string video = String.Format("../../Video/{0}.wmv", Session["video"].ToString());
        userLabel.Text = Session["user"].ToString();
        placeLabel.Text = Session["place"].ToString();

        tripMediaPlayer.Attributes["src"] = video;
    }
}