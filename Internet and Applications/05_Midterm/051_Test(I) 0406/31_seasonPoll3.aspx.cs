using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _05_Midterm_051_Test_I__0406_31_seasonPoll3 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            seasonRadioButtonList.SelectedIndex = 0;

            timeLabel.Text = DateTime.Now.ToString();
        }
    }
    protected void seasonRadioButtonList_SelectedIndexChanged(object sender, EventArgs e)
    {
        seasonFormView.PageIndex = seasonRadioButtonList.SelectedIndex;
    }
    protected void goButton_Click(object sender, EventArgs e)
    {
        Session["seasonId"] = seasonRadioButtonList.SelectedValue;
        Session["pollTime"] = timeLabel.Text;
        pollSqlDataSource.Insert();
        Response.Redirect("32_pollGrid2.aspx");
    }
}