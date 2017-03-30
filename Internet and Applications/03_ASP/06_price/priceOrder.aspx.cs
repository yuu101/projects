using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _03_ASP_06_price_priceOrder : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        userLabel.Text = Session["user"].ToString();
        placeLabel.Text = Session["place"].ToString();
        string youtubeId = Session["youtubeId"].ToString();
        youtubeIdHiddenField.Value = youtubeId;

        priceLabel.Text = string.Format("{0:N0}", Convert.ToInt32(Session["price"].ToString()));
        daysLabel.Text = Session["days"].ToString();
        totalLabel.Text = Session["total"].ToString();


        tripDateLabel.Text = Session["tripDate"].ToString();
    }
    protected void youtubeIdHiddenField_ValueChanged(object sender, EventArgs e)
    {

    }
}