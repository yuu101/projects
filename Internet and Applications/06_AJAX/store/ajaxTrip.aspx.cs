using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _06_AJAX_store_ajaxTrip : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            placeRadioButtonList.SelectedIndex = 0;
            placeFormView.PageIndex = 0;
            daysTextBox.Text = "5";

            tripCalendar.SelectedDate = DateTime.Now;        
        }
    }


    protected void placeRadioButtonList_SelectedIndexChanged(object sender, EventArgs e)
    {
        placeFormView.PageIndex = placeRadioButtonList.SelectedIndex;

    }
    protected void placeFormView_DataBound(object sender, EventArgs e)
    {
        HiddenField priceHiddenField = (HiddenField)placeFormView.FindControl("priceHiddenField");
        Label priceLabel = (Label)placeFormView.FindControl("priceLabel");
        priceLabel.Text = string.Format("{0:N0}", Convert.ToInt32(priceHiddenField.Value));
        totalHiddenField.Value=(Convert.ToInt32(priceHiddenField.Value)* Convert.ToInt32(daysTextBox.Text)).ToString();
        totalLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(totalHiddenField.Value)));
    }

    protected void daysTextBox_TextChanged(object sender, EventArgs e)
    {
        HiddenField priceHiddenField = (HiddenField)placeFormView.FindControl("priceHiddenField");
        totalHiddenField.Value=(Convert.ToInt32(priceHiddenField.Value)* Convert.ToInt32(daysTextBox.Text)).ToString();
        totalLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(totalHiddenField.Value)));
    }


    protected void goButton_Click(object sender, EventArgs e)
    {
        Session["userName"] = userTextBox.Text;
        Session["tourId"] = placeRadioButtonList.SelectedValue;
        Session["place"] = placeRadioButtonList.SelectedItem.Text;
        HiddenField youtubeIdHiddenField = (HiddenField)placeFormView.FindControl("youtubeIdHiddenField");
        Session["youtubeId"] = youtubeIdHiddenField.Value;

        Label priceLabel = (Label)placeFormView.FindControl("priceLabel");
        Session["price"] = priceLabel.Text;
        Session["days"] = daysTextBox.Text;

        Session["totalHiddenField"] = totalHiddenField.Value;
        Session["total"] = totalLabel.Text;

        Session["tripDate"] = tripCalendar.SelectedDate.ToShortDateString();

        Response.Redirect("../../04_Database/store/order.aspx");
    }




}