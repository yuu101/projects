<%@ Page Language="C#" AutoEventWireup="true" CodeFile="10_season.aspx.cs" Inherits="_05_Midterm_051_Test_I__0406_10_season" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>season</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />

</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <div style="height: 581px; width: 495px">
            <span class="title">我提供這些季節的剪影</span><br />
            <br />
            <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="seasonId" DataSourceID="seasonSqlDataSource" ForeColor="#333333" GridLines="None" Height="221px" Width="479px">
                <AlternatingRowStyle BackColor="White" />
                <Columns>
                    <asp:BoundField DataField="seasonId" HeaderText="序號" InsertVisible="False" ReadOnly="True" SortExpression="seasonId" />
                    <asp:BoundField DataField="season" HeaderText="季節" SortExpression="season" />
                    <asp:BoundField DataField="flickrId" HeaderText="Flickr 照片" SortExpression="flickrId" />
                    <asp:CommandField HeaderText="管理" ShowDeleteButton="True" ShowEditButton="True" />
                </Columns>
                <EditRowStyle BackColor="#2461BF" />
                <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />
                <RowStyle BackColor="#EFF3FB" />
                <SelectedRowStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
                <SortedAscendingCellStyle BackColor="#F5F7FB" />
                <SortedAscendingHeaderStyle BackColor="#6D95E1" />
                <SortedDescendingCellStyle BackColor="#E9EBEF" />
                <SortedDescendingHeaderStyle BackColor="#4870BE" />
            </asp:GridView>
            <br />
            <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False" CellPadding="4" DataKeyNames="seasonId" DataSourceID="seasonSqlDataSource" DefaultMode="Insert" ForeColor="#333333" GridLines="None" Height="50px" Width="400px">
                <AlternatingRowStyle BackColor="White" />
                <CommandRowStyle BackColor="#D1DDF1" Font-Bold="True" />
                <EditRowStyle BackColor="#2461BF" />
                <FieldHeaderStyle BackColor="#DEE8F5" Font-Bold="True" />
                <Fields>
                    <asp:BoundField DataField="season" HeaderText="季節" SortExpression="season" />
                    <asp:BoundField DataField="flickrId" HeaderText="Flickr 照片" SortExpression="flickrId" />
                    <asp:CommandField HeaderText="新增" InsertText="新增" ShowInsertButton="True" />
                </Fields>
                <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />
                <RowStyle BackColor="#EFF3FB" />
            </asp:DetailsView>
            <br />
            <asp:SqlDataSource ID="seasonSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [season] WHERE [seasonId] = @seasonId" InsertCommand="INSERT INTO [season] ([season], [flickrId]) VALUES (@season, @flickrId)" SelectCommand="SELECT * FROM [season]" UpdateCommand="UPDATE [season] SET [season] = @season, [flickrId] = @flickrId WHERE [seasonId] = @seasonId">
                <DeleteParameters>
                    <asp:Parameter Name="seasonId" Type="Int32" />
                </DeleteParameters>
                <InsertParameters>
                    <asp:Parameter Name="season" Type="String" />
                    <asp:Parameter Name="flickrId" Type="String" />
                </InsertParameters>
                <UpdateParameters>
                    <asp:Parameter Name="season" Type="String" />
                    <asp:Parameter Name="flickrId" Type="String" />
                    <asp:Parameter Name="seasonId" Type="Int32" />
                </UpdateParameters>
            </asp:SqlDataSource>
            <br />
        </div>
    
    </div>
    </form>
</body>
</html>
