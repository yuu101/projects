using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _10_Facebook_tripMenu : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        var loginProvider = Request.Params["loginProvider"];

        if (loginProvider != null)
            login();
        else
            logout();
    }

    private void logout()
    {
        Session["loginProvider"] = null;
        Session["googleMail"] = null;
        Session["fbMail"] = null;
        Session["userName"] = null;
        Session["picture"] = null;
        Session["email"] = null;
    }

    private void login()
    {
        var loginProvider = Request.Params["loginProvider"];
        Session["loginProvider"] = loginProvider;

        Session["userName"] = Request.Params["name"];
        Session["picture"] = Request.Params["picture"];
        Session["email"] = Request.Params["email"];
        Session[loginProvider + "Mail"] = Request.Params["email"];
        DataView queryResult = (DataView)roleSqlDataSource.Select(DataSourceSelectArguments.Empty);
        if (queryResult.Count == 0)
        {
            Session["role"] = "1";
            userSqlDataSource.Insert();
        }
        else
        {
            Session["role"] = (string)queryResult.Table.Rows[0]["role"];
        }

        userImage.ImageUrl = Session["picture"].ToString();
        userImage.Visible = true;
        nameLabel.Text = "旅行者：" + Session["userName"].ToString();
        nameLabel.Visible = true;
        emailLabel.Text = Session["email"].ToString();
        emailLabel.Visible = true;

        int role = int.Parse((string)Session["role"]);
        switch (role)
        {
            case 0:
                tripTreeView.DataSourceID = "anonymousSiteMapDataSource";
                break;
            case 1:
                tripTreeView.DataSourceID = "customerSiteMapDataSource";
                break;
            case 2:
                tripTreeView.DataSourceID = "managerSiteMapDataSource";
                break;
            case 3:
                tripTreeView.DataSourceID = "adminSiteMapDataSource";
                break;
        }
    }
}