using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _10_Facebook_store_Trip : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        userLabel.Text = Session["userName"].ToString();

        if (!IsPostBack)
        {
            placeRadioButtonList.SelectedIndex = 0;
            daysTextBox.Text = "5";
            tripDateHiddenField.Value = DateTime.Now.ToShortDateString();
        }
    }

    protected void placeRadioButtonList_DataBound(object sender, EventArgs e)
    {
        foreach (ListItem item in placeRadioButtonList.Items)
        {
            item.Attributes["onclick"] = "placeRadioButtonList_onclick(" + item.Value + ");";
        }
    }


    protected void goButton_Click(object sender, EventArgs e)
    {
        Session["userName"] = userLabel.Text;
        Session["tourId"] = placeRadioButtonList.SelectedValue;
        Session["place"] = placeRadioButtonList.SelectedItem.Text;
        Session["youtubeId"] = youtubeIdHiddenField.Value;

        Session["price"] = priceHiddenField.Value;
        Session["days"] = daysTextBox.Text;
        Session["totalHidden"] = totalHiddenField.Value;

        Session["tripDate"] = tripDateHiddenField.Value;
        Session["latitude"] = latitudeHiddenField.Value;
        Session["longitude"] = longitudeHiddenField.Value;

        Response.Redirect("order.aspx");
    }





}