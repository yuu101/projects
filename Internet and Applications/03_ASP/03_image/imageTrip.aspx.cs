using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _03_ASP_03_image_imageTrip : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            placeRadioButtonList.SelectedIndex = 0;
            string photoId = "ToKyo";
            string youtubeId = "O8aUP64bO7o";

            placeImage.ImageUrl = "../../Image/" + photoId + ".jpg";
            youtubeIdHiddenField.Value = youtubeId;

        }
    }
    protected void goButton_Click(object sender, EventArgs e)
    {
        Session["user"] = userTextBox.Text;
        Session["placeId"] = placeRadioButtonList.SelectedValue;
        Session["place"] = placeRadioButtonList.SelectedItem.Text;
        Session["youtubeId"] = youtubeIdHiddenField.Value;         

        Response.Redirect("imageOrder.aspx");
    }


    protected void placeRadioButtonList_SelectedIndexChanged(object sender, EventArgs e)
    {
        string photoId = "";
        string youtubeId = "";

        switch (placeRadioButtonList.SelectedValue)
        {
            case "1":
                photoId = "Tokyo";
                youtubeId = "O8aUP64bO7o";
                break;

            case "2":
                photoId = "NewYork";
                youtubeId = "m_OBpeO8iMk";
                break;

            case "3":
                photoId = "London";
                youtubeId = "tO2VoFcJ_4I";
                break;
        }

        placeImage.ImageUrl = "../../Image/" + photoId + ".jpg";
        youtubeIdHiddenField.Value = youtubeId;
        
    }
}