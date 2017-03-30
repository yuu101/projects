using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _05_Midterm_052_Test_II__0412_31_movieGrade3 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            movieRadioButtonList.SelectedIndex = 0;
            timeLabel.Text = DateTime.Now.ToString();
        }
    }
    protected void goButton_Click(object sender, EventArgs e)
    {
        Session["movieId"] = movieRadioButtonList.SelectedValue;
        Session["grade"] = gradeDropDownList.SelectedValue;
        Session["gradeTime"] = timeLabel.Text;
        gradeSqlDataSource.Insert();

        Response.Redirect("32_gradeGrid2.aspx");

    }
    protected void movieRadioButtonList_SelectedIndexChanged(object sender, EventArgs e)
    {
        movieFormView.PageIndex = movieRadioButtonList.SelectedIndex;
    }
}