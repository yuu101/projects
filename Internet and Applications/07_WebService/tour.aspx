<%@ Page Language="C#" AutoEventWireup="true" CodeFile="tour.aspx.cs" Inherits="_07_WebService_tour" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>tour</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />

</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <div style="height: 800px; width: 682px">
            <span class="title">商品管理<br />
            </span>
            <br />
            <br />
            <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="tourId" DataSourceID="tourSqlDataSource" ForeColor="#333333" GridLines="None">
                <AlternatingRowStyle BackColor="White" />
                <Columns>
                    <asp:BoundField DataField="tourId" HeaderText="序號" InsertVisible="False" ReadOnly="True" SortExpression="tourId" />
                    <asp:BoundField DataField="place" HeaderText="地點" SortExpression="place" />
                    <asp:BoundField DataField="price" DataFormatString="{0:N0}" HeaderText="價格" SortExpression="price" />
                    <asp:BoundField DataField="flickrId" HeaderText="Flickr 照片" SortExpression="flickrId" />
                    <asp:BoundField DataField="youtubeId" HeaderText="Youtube 影片" SortExpression="youtubeId" />
                    <asp:BoundField DataField="latitude" HeaderText="緯度" SortExpression="latitude" />
                    <asp:BoundField DataField="longitude" HeaderText="經度" SortExpression="longitude" />
                    <asp:CommandField ButtonType="Button" HeaderText="管理" ShowDeleteButton="True" ShowEditButton="True" />
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
            <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False" CellPadding="4" DataKeyNames="tourId" DataSourceID="tourSqlDataSource" DefaultMode="Insert" ForeColor="#333333" GridLines="None" Height="50px" Width="400px">
                <AlternatingRowStyle BackColor="White" />
                <CommandRowStyle BackColor="#D1DDF1" Font-Bold="True" />
                <EditRowStyle BackColor="#2461BF" />
                <FieldHeaderStyle BackColor="#DEE8F5" Font-Bold="True" />
                <Fields>
                    <asp:BoundField DataField="tourId" HeaderText="序號" InsertVisible="False" ReadOnly="True" SortExpression="tourId" />
                    <asp:BoundField DataField="place" HeaderText="地點" SortExpression="place" />
                    <asp:BoundField DataField="price" HeaderText="價格" SortExpression="price" />
                    <asp:BoundField DataField="flickrId" HeaderText="Flickr 照片" SortExpression="flickrId" />
                    <asp:BoundField DataField="youtubeId" HeaderText="Youtube 影片" SortExpression="youtubeId" />
                    <asp:BoundField DataField="latitude" HeaderText="緯度" SortExpression="latitude" />
                    <asp:BoundField DataField="longitude" HeaderText="經度" SortExpression="longitude" />
                    <asp:CommandField ButtonType="Button" InsertText="新增" ShowInsertButton="True" />
                </Fields>
                <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />
                <RowStyle BackColor="#EFF3FB" />
            </asp:DetailsView>
            <br />
            <br />
            <asp:SqlDataSource ID="tourSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [tour] WHERE [tourId] = @tourId" InsertCommand="INSERT INTO [tour] ([place], [price], [flickrId], [youtubeId], [latitude], [longitude]) VALUES (@place, @price, @flickrId, @youtubeId, @latitude, @longitude)" SelectCommand="SELECT * FROM [tour]" UpdateCommand="UPDATE [tour] SET [place] = @place, [price] = @price, [flickrId] = @flickrId, [youtubeId] = @youtubeId, [latitude] = @latitude, [longitude] = @longitude WHERE [tourId] = @tourId">
                <DeleteParameters>
                    <asp:Parameter Name="tourId" Type="Int32" />
                </DeleteParameters>
                <InsertParameters>
                    <asp:Parameter Name="place" Type="String" />
                    <asp:Parameter Name="price" Type="Int32" />
                    <asp:Parameter Name="flickrId" Type="String" />
                    <asp:Parameter Name="youtubeId" Type="String" />
                    <asp:Parameter Name="latitude" Type="Double" />
                    <asp:Parameter Name="longitude" Type="Double" />
                </InsertParameters>
                <UpdateParameters>
                    <asp:Parameter Name="place" Type="String" />
                    <asp:Parameter Name="price" Type="Int32" />
                    <asp:Parameter Name="flickrId" Type="String" />
                    <asp:Parameter Name="youtubeId" Type="String" />
                    <asp:Parameter Name="latitude" Type="Double" />
                    <asp:Parameter Name="longitude" Type="Double" />
                    <asp:Parameter Name="tourId" Type="Int32" />
                </UpdateParameters>
            </asp:SqlDataSource>
            <br />
        </div>
    
    </div>
    </form>
</body>
</html>
