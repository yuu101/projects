using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _03_ASP_06_price_priceTrip : System.Web.UI.Page
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

            priceLabel.Text = "1000";
            daysTextBox.Text = "5";
            totalLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(priceLabel.Text) * Convert.ToInt32(daysTextBox.Text)));
            priceLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(priceLabel.Text)));

            tripCalendar.SelectedDate = DateTime.Now;
        }
    }
    protected void goButton_Click(object sender, EventArgs e)
    {
        Session["user"] = userTextBox.Text;
        Session["placeId"] = placeRadioButtonList.SelectedValue;
        Session["place"] = placeRadioButtonList.SelectedItem.Text;
        Session["youtubeId"] = youtubeIdHiddenField.Value;

        Session["price"] = priceHiddenField.Value;
        Session["days"] = daysTextBox.Text;
        Session["total"] = totalLabel.Text;

        Session["tripDate"] = tripCalendar.SelectedDate.ToShortDateString();
        Response.Redirect("priceOrder.aspx");
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
                priceHiddenField.Value = "1000";
                break;

            case "2":
                photoId = "7414/13054804873_72be81e8dd_o";
                youtubeId = "m_OBpeO8iMk";
                priceHiddenField.Value = "3000";
                break;

            case "3":
                photoId = "7379/13054804823_c238094830_o";
                youtubeId = "tO2VoFcJ_4I";
                priceHiddenField.Value = "5000";
                break;
        }

        placeImage.ImageUrl = "https://farm9.staticflickr.com/" + photoId + ".jpg";
        youtubeIdHiddenField.Value = youtubeId;
        totalLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(priceHiddenField.Value) * Convert.ToInt32(daysTextBox.Text)));
        priceLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(priceHiddenField.Value)));

    }
    protected void daysTextBox_OnTextChanged(object sender, EventArgs e)
    {
        totalLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(priceHiddenField.Value) * Convert.ToInt32(daysTextBox.Text)));
    }
}