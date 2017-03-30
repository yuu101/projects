<%@ Page Language="C#" AutoEventWireup="true" CodeFile="tripMenu.aspx.cs" Inherits="_10_Facebook_tripMenu" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <link href="../Styles/tripStyleSheet.css" rel="stylesheet" />
</head>
<body>
    <form id="form1" runat="server" style="margin-top:4em;">
    <div class="body">
    
        <table>
            <tr>
                <td>
                    <input id="fbLoginButton" type="button" value="Facebook登入" onclick="facebookLogin()"/>&nbsp;&nbsp;&nbsp;&nbsp;
                    <input id="googleLoginButton" type="button" value="Google登入" onclick="googleLogin()" /></td>
            </tr>
            <tr>
                <td>
                    <asp:Image ID="userImage" runat="server" Visible="False" />
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="nameLabel" runat="server" Text="Label" Visible="False"></asp:Label>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Label ID="emailLabel" runat="server" Text="Label" Visible="False"></asp:Label>
                </td>
            </tr>
            <tr>
                <td>
                    <input id="logoutButton" type="button" value="登出" onclick="logout()" style="display:none;"  /></td>
            </tr>
            <tr>
                <td>
                    <asp:TreeView ID="tripTreeView" runat="server" DataSourceID="annoymousSiteMapDataSource" ShowExpandCollapse="False" Target="mainFrame">
                    </asp:TreeView>
                    <asp:SiteMapDataSource ID="annoymousSiteMapDataSource" runat="server" SiteMapProvider="XmlSiteMapProvider_Security0" />
                    <asp:SiteMapDataSource ID="customerSiteMapDataSource" runat="server" SiteMapProvider="XmlSiteMapProvider_Security1" />
                    <asp:SiteMapDataSource ID="managerSiteMapDataSource" runat="server" SiteMapProvider="XmlSiteMapProvider_Security2" />
                    <asp:SiteMapDataSource ID="adminSiteMapDataSource" runat="server" SiteMapProvider="XmlSiteMapProvider_Security3" />
                    <br />
                    <asp:SqlDataSource ID="roleSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT userId, userName, picture, fbMail, googleMail, role FROM [user] WHERE (fbMail = @fbMail) OR (googleMail = @googleMail)">
                        <SelectParameters>
                            <asp:SessionParameter DefaultValue="&quot;&quot;" Name="fbMail" SessionField="fbMail" />
                            <asp:SessionParameter DefaultValue="&quot;&quot;" Name="googleMail" SessionField="googleMail" />
                        </SelectParameters>
                    </asp:SqlDataSource>
                    <asp:SqlDataSource ID="userSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [user] WHERE [Id] = @Id" InsertCommand="INSERT INTO [user] ([userName], [picture], [fbMail], [googleMail], [role]) VALUES (@userName, @picture, @fbMail, @googleMail, @role)" SelectCommand="SELECT * FROM [user]" UpdateCommand="UPDATE [user] SET [userName] = @userName, [picture] = @picture, [fbMail] = @fbMail, [googleMail] = @googleMail, [role] = @role WHERE [userId] = @Id">
                        <DeleteParameters>
                            <asp:Parameter Name="userId" Type="Int32" />
                        </DeleteParameters>
                        <InsertParameters>
                            <asp:SessionParameter Name="userName" SessionField="userName" Type="String" />
                            <asp:SessionParameter Name="picture" SessionField="picture" Type="String" />
                            <asp:SessionParameter Name="fbMail" SessionField="fbMail" Type="String" />
                            <asp:SessionParameter Name="googleMail" SessionField="googleMail" Type="String" />
                            <asp:SessionParameter Name="role" SessionField="role" Type="String" />
                        </InsertParameters>
                        <UpdateParameters>
                            <asp:Parameter Name="userName" Type="String" />
                            <asp:Parameter Name="picture" Type="String" />
                            <asp:Parameter Name="fbMail" Type="String" />
                            <asp:Parameter Name="googleMail" Type="String" />
                            <asp:Parameter Name="role" Type="String" />
                            <asp:Parameter Name="userId" Type="Int32" />
                        </UpdateParameters>
                    </asp:SqlDataSource>
                    <br />
                </td>
            </tr>
        </table>
    
    </div>
    </form>
</body>
</html>
<script src="../Scripts/jquery-1.10.2.js"></script>
<script src="../JavaScript/tripInit.js"></script>

<script>
    var loginProvider = '<%= Session["loginProvider"]%>';
</script>

<script src="../Javascript/logout.js"></script>

<script src="../Javascript/fBLogin.js"></script>
<script src="../Javascript/fbLogout.js"></script>
<script type="text/javascript" src="//connect.facebook.net/en_US/all.js"></script>

<script src="../Javascript/googleLogin.js"></script>
<script src="../Javascript/googleLogout.js"></script>
<script type="text/javascript" src="//apis.google.com/js/client.js?onload=onLoadCallback"></script>

