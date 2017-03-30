using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _03_ASP_04_flickr_flickrTrip : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            placeRadioButtonList.SelectedIndex = 0;
            string photoId = "2035/13054988514_caa39974cc_o";
            string youtubeId = "O8aUP64bO7o";

            placeImage.ImageUrl = "https://farm9.staticflickr.com/" + photoId + ".jpg";
            youtubeIdHiddenField.Value = youtubeId;

        }
    }
    protected void goButton_Click(object sender, EventArgs e)
    {
        Session["user"] = userTextBox.Text;
        Session["placeId"] = placeRadioButtonList.SelectedValue;
        Session["place"] = placeRadioButtonList.SelectedItem.Text;
        Session["youtubeId"] = youtubeIdHiddenField.Value;         

        Response.Redirect("flickrOrder.aspx");
    }


    protected void placeRadioButtonList_SelectedIndexChanged(object sender, EventArgs e)
    {
        string photoId = "";
        string youtubeId = "";

        switch (placeRadioButtonList.SelectedValue)
        {
            case "1":
                photoId = "2035/13054988514_caa39974cc_o";
                youtubeId = "O8aUP64bO7o";
                break;

            case "2":
                photoId = "7414/13054804873_72be81e8dd_o";
                youtubeId = "m_OBpeO8iMk";
                break;

            case "3":
                photoId = "7379/13054804823_c238094830_o";
                youtubeId = "tO2VoFcJ_4I";
                break;
        }

        placeImage.ImageUrl = "https://farm9.staticflickr.com/" + photoId + ".jpg";
        youtubeIdHiddenField.Value = youtubeId;
        
    }
}