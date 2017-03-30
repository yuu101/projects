<%@ Page Language="C#" AutoEventWireup="true" CodeFile="edit.aspx.cs" Inherits="_099_myMovie_admin_edit" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Edit</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />

</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <div style="height: 800px; width: 682px">
            <span class="title">電影管理<br />
            </span>
            <br />
            <br />
            <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="movieId" DataSourceID="movieSqlDataSource" ForeColor="Black" GridLines="Horizontal" BackColor="White" BorderColor="#CCCCCC" BorderStyle="None" BorderWidth="1px">
                <Columns>
                    <asp:BoundField DataField="movieId" HeaderText="序號" InsertVisible="False" ReadOnly="True" SortExpression="movieId" />
                    <asp:BoundField DataField="movieName" HeaderText="電影名稱" SortExpression="movieName" />
                    <asp:BoundField DataField="movieEngName" HeaderText="English Name" SortExpression="movieEngName" />
                    <asp:BoundField DataField="time" HeaderText="片長" SortExpression="time" />
                    <asp:BoundField DataField="intro" HeaderText="簡介" SortExpression="intro" />
                    <asp:BoundField DataField="imageUrl" HeaderText="圖片網址" SortExpression="imageUrl" />
                    <asp:BoundField DataField="youtubeId" HeaderText="youtube 影片" SortExpression="youtubeId" />
                    <asp:CommandField ButtonType="Button" ShowDeleteButton="True" ShowEditButton="True" />
                </Columns>
                <FooterStyle BackColor="#CCCC99" ForeColor="Black" />
                <HeaderStyle BackColor="#333333" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="White" ForeColor="Black" HorizontalAlign="Right" />
                <SelectedRowStyle BackColor="#CC3333" Font-Bold="True" ForeColor="White" />
                <SortedAscendingCellStyle BackColor="#F7F7F7" />
                <SortedAscendingHeaderStyle BackColor="#4B4B4B" />
                <SortedDescendingCellStyle BackColor="#E5E5E5" />
                <SortedDescendingHeaderStyle BackColor="#242121" />
            </asp:GridView>
            <br />
            <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False" CellPadding="4" DataKeyNames="movieId" DataSourceID="movieSqlDataSource" DefaultMode="Insert" ForeColor="Black" GridLines="Horizontal" Height="50px" Width="400px" BackColor="White" BorderColor="#CCCCCC" BorderStyle="None" BorderWidth="1px">
                <EditRowStyle BackColor="#CC3333" Font-Bold="True" ForeColor="White" />
                <Fields>
                    <asp:BoundField DataField="movieName" HeaderText="電影名稱" SortExpression="movieName" />
                    <asp:BoundField DataField="movieEngName" HeaderText="English Name" SortExpression="movieEngName" />
                    <asp:BoundField DataField="time" HeaderText="片長" SortExpression="time" />
                    <asp:BoundField DataField="intro" HeaderText="簡介" SortExpression="intro" />
                    <asp:BoundField DataField="imageUrl" HeaderText="圖片網址" SortExpression="imageUrl" />
                    <asp:BoundField DataField="youtubeId" HeaderText="youtube 影片" SortExpression="youtubeId" />
                    <asp:CommandField InsertText="新增" ShowInsertButton="True" />
                </Fields>
                <FooterStyle BackColor="#CCCC99" ForeColor="Black" />
                <HeaderStyle BackColor="#333333" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="White" ForeColor="Black" HorizontalAlign="Right" />
            </asp:DetailsView>
            <br />
            <br />
            <asp:SqlDataSource ID="movieSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [movie] WHERE [movieId] = @movieId" InsertCommand="INSERT INTO [movie] ([movieName], [time], [imageUrl], [youtubeId], [movieEngName], [intro]) VALUES (@movieName, @time, @imageUrl, @youtubeId, @movieEngName, @intro)" SelectCommand="SELECT * FROM [movie]" UpdateCommand="UPDATE [movie] SET [movieName] = @movieName, [time] = @time, [imageUrl] = @imageUrl, [youtubeId] = @youtubeId, [movieEngName] = @movieEngName, [intro] = @intro WHERE [movieId] = @movieId">
                <DeleteParameters>
                    <asp:Parameter Name="movieId" Type="Int32" />
                </DeleteParameters>
                <InsertParameters>
                    <asp:Parameter Name="movieName" Type="String" />
                    <asp:Parameter Name="time" Type="String" />
                    <asp:Parameter Name="imageUrl" Type="String" />
                    <asp:Parameter Name="youtubeId" Type="String" />
                    <asp:Parameter Name="movieEngName" Type="String" />
                    <asp:Parameter Name="intro" Type="String" />
                </InsertParameters>
                <UpdateParameters>
                    <asp:Parameter Name="movieName" Type="String" />
                    <asp:Parameter Name="time" Type="String" />
                    <asp:Parameter Name="imageUrl" Type="String" />
                    <asp:Parameter Name="youtubeId" Type="String" />
                    <asp:Parameter Name="movieEngName" Type="String" />
                    <asp:Parameter Name="intro" Type="String" />
                    <asp:Parameter Name="movieId" Type="Int32" />
                </UpdateParameters>
            </asp:SqlDataSource>
            <br />
        </div>
    
    </div>
    </form>
</body>
</html>
