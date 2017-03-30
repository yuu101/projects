using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _04_Database_store_Order : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        userLabel.Text = Session["userName"].ToString();
        placeLabel.Text = Session["place"].ToString();
        youtubeIdHiddenField.Value = Session["youtubeId"].ToString();

        priceLabel.Text = Session["price"].ToString();
        daysLabel.Text = Session["days"].ToString();
        totalHiddenField.Value = Session["totalHiddenField"].ToString();
        totalLabel.Text = Session["total"].ToString();

        tripDateLabel.Text = Session["tripDate"].ToString();
    }
    protected void orderButton_Click(object sender, EventArgs e)
    {
        tripSqlDataSource.Insert();
        Response.Redirect("tripList.aspx"); 
    }

}