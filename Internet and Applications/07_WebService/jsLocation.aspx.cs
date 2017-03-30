using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _07_WebService_jsLocation : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        placeRadioButtonList.SelectedIndex = 0;
    }
    protected void placeRadioButtonList_DataBound(object sender, EventArgs e)
    {
        foreach (ListItem item in placeRadioButtonList.Items)
        {
            item.Attributes["Onclick"] = "placeRadioButtonList_onclick(" + item.Value + ");";
        }
    }
}