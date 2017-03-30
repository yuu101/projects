using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _05_Midterm_052_Test_II__0412_41_gradeGrid3 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        
    }
    protected void DataList1_ItemCommand(object source, DataListCommandEventArgs e)
    {
        Session["index"] = e.Item.ItemIndex +1;
        FormView1.PageIndex = e.Item.ItemIndex;
    }
}