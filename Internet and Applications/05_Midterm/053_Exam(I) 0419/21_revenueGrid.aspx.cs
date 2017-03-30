using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _05_Midterm_053_Exam_I__0419_21_revenueGrid : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        FormView1.PageIndex = 0;
    }
    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {
        FormView1.PageIndex = GridView1.SelectedIndex;
    }

}