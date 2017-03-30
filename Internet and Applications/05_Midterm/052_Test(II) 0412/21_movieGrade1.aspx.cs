using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _05_Midterm_052_Test_II__0412_21_movieGrade1 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            movieRadioButtonList.SelectedIndex = 0;
        }
    }
    protected void goButton_Click(object sender, EventArgs e)
    {
        Session["movieId"] = movieRadioButtonList.SelectedValue;
        Session["grade"] = gradeDropDownList.SelectedValue;
        gradeSqlDataSource.Insert();
        Response.Redirect("23_gradeGrid1.aspx");
    }
}