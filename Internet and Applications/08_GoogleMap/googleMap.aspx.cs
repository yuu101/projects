using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _08_GoogleMap_googleMap : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            placeRadioButtonList.SelectedIndex = 0;
        }
    }
    protected void placeRadioButtonList_DataBinding(object sender, EventArgs e)
    {
        foreach (ListItem item in placeRadioButtonList.Items)
        {
            item.Attributes["Onclick"] = "placeRadioButtonList_onclick(" + item.Value + ");";
        }
    }
}