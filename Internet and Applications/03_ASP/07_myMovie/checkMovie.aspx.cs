using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _03_ASP_07_myMovie_checkMovie : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        titleLabel.Text = Session["title"].ToString();
        engLabel.Text = Session["eng"].ToString();
        priceLabel.Text = Session["price"].ToString();
        ticketsLabel.Text = Session["tickets"].ToString();
        totalLabel.Text = Session["total"].ToString();


    }
}