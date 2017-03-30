using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _06_AJAX_vote_ajaxVoteReal : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            RadioButtonList1.SelectedIndex = 0;
            RadioButtonList2.SelectedIndex = 0;
        }
    }
    protected void RadioButtonList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        FormView1.PageIndex = RadioButtonList1.SelectedIndex;
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        SqlDataSource2.Insert();
        DataList1.DataBind();
    }
    protected void RadioButtonList2_SelectedIndexChanged(object sender, EventArgs e)
    {
        FormView2.PageIndex = RadioButtonList2.SelectedIndex;
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        SqlDataSource5.Insert();
        DataList2.DataBind();
      
    }
    protected void youtubeIdHiddenField_ValueChanged(object sender, EventArgs e)
    {

    }
    protected void FormView2_DataBound(object sender, EventArgs e)
    {
       // HiddenField HiddenField2 = (HiddenField)FormView2.FindControl("HiddenField2");
        //youtubeHiddenField.Value = HiddenField2.Value;
    }
    protected void UpdatePanel1_Load(object sender, EventArgs e)
    {
        ScriptManager.RegisterStartupScript(this.UpdatePanel1, this.GetType(), "ajaxScript", "onYouTubeIframeAPIReady();", true);
    }
    protected void DataList2_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
}