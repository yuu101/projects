using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _05_Midterm_053_Exam_I__0419_12_imageBuy : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            FormView1.PageIndex = DropDownList1.SelectedIndex;
            Label price = (Label)FormView1.FindControl("priceLabel");
            int total = (Convert.ToInt32(price.Text) * Convert.ToInt32(RadioButtonList1.SelectedValue));
            totalLabel.Text = string.Format("{0:N0}",total);
            Session["total"] = total;
        }
    }
    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        FormView1.PageIndex = DropDownList1.SelectedIndex;
    }
    protected void RadioButtonList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        Label price = (Label)FormView1.FindControl("priceLabel");
        int total = (Convert.ToInt32(price.Text) * Convert.ToInt32(RadioButtonList1.SelectedValue));
        totalLabel.Text = string.Format("{0:N0}", total);
        Session["total"] = total;
    }
    protected void FormView1_DataBound(object sender, EventArgs e)
    {
        Label price = (Label)FormView1.FindControl("priceLabel");
        int total = (Convert.ToInt32(price.Text) * Convert.ToInt32(RadioButtonList1.SelectedValue));
        totalLabel.Text = string.Format("{0:N0}", total);
        Session["total"] = total;
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        SqlDataSource2.Insert();
        Response.Redirect("13_salesGrid.aspx");  
    }
}