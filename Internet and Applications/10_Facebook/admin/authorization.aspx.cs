using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _10_Facebook_admin_authorization : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void roleRadioButtonList_SelectedIndexChanged(object sender, EventArgs e)
    {
        GridViewRow gridViewContainer = (GridViewRow)((RadioButtonList)sender).NamingContainer;

        HiddenField userIdHiddenField = (HiddenField)gridViewContainer.FindControl("userIdHiddenField");
        RadioButtonList roleRadioButtonList = (RadioButtonList)gridViewContainer.FindControl("roleRadioButtonList");

        Session["userId"] = userIdHiddenField.Value;
        Session["roleValue"] = roleRadioButtonList.SelectedValue;

        memberListSqlDataSource.Update();
    }
}