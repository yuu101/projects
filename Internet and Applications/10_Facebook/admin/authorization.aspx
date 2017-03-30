<%@ Page Language="C#" AutoEventWireup="true" CodeFile="authorization.aspx.cs" Inherits="_10_Facebook_admin_authorization" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>authorization</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
</head>
<body>
    <form id="form1" runat="server">
    <div class="body">
    
        <span class="title">權限管理</span><br />
        <br />
        <asp:GridView ID="authorizationGridView" runat="server" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="userId" DataSourceID="memberListSqlDataSource" ForeColor="#333333" GridLines="None">
            <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
            <Columns>
                <asp:BoundField DataField="userId" HeaderText="序號" InsertVisible="False" ReadOnly="True" SortExpression="userId" />
                <asp:BoundField DataField="userName" HeaderText="姓名" SortExpression="userName" />
                <asp:ImageField DataImageUrlField="picture" HeaderText="照片">
                </asp:ImageField>
                <asp:TemplateField HeaderText="權限">
                    <ItemTemplate>
                        <asp:RadioButtonList ID="roleRadioButtonList" runat="server" AutoPostBack="True" OnSelectedIndexChanged="roleRadioButtonList_SelectedIndexChanged" RepeatDirection="Horizontal" SelectedValue='<%# Bind("role") %>'>
                            <asp:ListItem Value="0">anonymous</asp:ListItem>
                            <asp:ListItem Value="1">customer</asp:ListItem>
                            <asp:ListItem Value="2">manager</asp:ListItem>
                            <asp:ListItem Value="3">admin</asp:ListItem>
                        </asp:RadioButtonList>
                        <asp:HiddenField ID="userIdHiddenField" runat="server" Value='<%# Eval("userId") %>' />
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:CommandField ButtonType="Button" ShowDeleteButton="True" />
            </Columns>
            <EditRowStyle BackColor="#999999" />
            <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
            <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
            <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
            <SortedAscendingCellStyle BackColor="#E9E7E2" />
            <SortedAscendingHeaderStyle BackColor="#506C8C" />
            <SortedDescendingCellStyle BackColor="#FFFDF8" />
            <SortedDescendingHeaderStyle BackColor="#6F8DAE" />
        </asp:GridView>
        <br />
        <br />
        <asp:SqlDataSource ID="memberListSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [user] WHERE [Id] = @Id" InsertCommand="INSERT INTO [user] ([userName], [picture], [role]) VALUES (@userName, @picture, @role)" SelectCommand="SELECT [userId], [userName], [picture], [role] FROM [user]" UpdateCommand="UPDATE [user] SET role = @roleValue WHERE (userId = @userId)">
            <DeleteParameters>
                <asp:Parameter Name="Id" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="userName" Type="String" />
                <asp:Parameter Name="picture" Type="String" />
                <asp:Parameter Name="role" Type="String" />
            </InsertParameters>
            <UpdateParameters>
                <asp:SessionParameter Name="roleValue" SessionField="roleValue" />
                <asp:SessionParameter Name="userId" SessionField="userId" />
            </UpdateParameters>
        </asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
