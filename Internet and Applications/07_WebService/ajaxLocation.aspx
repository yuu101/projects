<%@ Page Language="C#" AutoEventWireup="true" CodeFile="ajaxLocation.aspx.cs" Inherits="_07_WebService_ajaxLocation" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>ajaxLocation</title>
    <link href="../Styles/tripStyleSheet.css" rel="stylesheet" />
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
    </style>
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">ASP UpdatePanel AJAX網頁</span><br />
        <br />
        <asp:ScriptManager ID="ScriptManager1" runat="server">
        </asp:ScriptManager>
        <asp:UpdatePanel ID="UpdatePanel1" runat="server" UpdateMode="Conditional">
            <ContentTemplate>
                <asp:RadioButtonList ID="placeRadioButtonList" runat="server" AutoPostBack="True" DataSourceID="placeSqlDataSource" DataTextField="place" DataValueField="tourId" OnSelectedIndexChanged="RadioButtonList1_SelectedIndexChanged" RepeatDirection="Horizontal">
                </asp:RadioButtonList>
                <asp:FormView ID="placeFormView" runat="server" DataKeyNames="tourId" DataSourceID="placeSqlDataSource" HorizontalAlign="Center">
                    <EditItemTemplate>
                        tourId:
                        <asp:Label ID="tourIdLabel1" runat="server" Text='<%# Eval("tourId") %>' />
                        <br />
                        place:
                        <asp:TextBox ID="placeTextBox" runat="server" Text='<%# Bind("place") %>' />
                        <br />
                        flickrId:
                        <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                        <br />
                        latitude:
                        <asp:TextBox ID="latitudeTextBox" runat="server" Text='<%# Bind("latitude") %>' />
                        <br />
                        longitude:
                        <asp:TextBox ID="longitudeTextBox" runat="server" Text='<%# Bind("longitude") %>' />
                        <br />
                        <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="更新" />
                        &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
                    </EditItemTemplate>
                    <InsertItemTemplate>
                        place:
                        <asp:TextBox ID="placeTextBox" runat="server" Text='<%# Bind("place") %>' />
                        <br />
                        flickrId:
                        <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                        <br />
                        latitude:
                        <asp:TextBox ID="latitudeTextBox" runat="server" Text='<%# Bind("latitude") %>' />
                        <br />
                        longitude:
                        <asp:TextBox ID="longitudeTextBox" runat="server" Text='<%# Bind("longitude") %>' />
                        <br />
                        <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="插入" />
                        &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
                    </InsertItemTemplate>
                    <ItemTemplate>
                        <table class="auto-style1">
                            <tr>
                                <td colspan="2">
                                    <asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("flickrId", "http://farm9.staticflickr.com/{0}") %>' />
                                </td>
                            </tr>
                            <tr>
                                <td>緯度:</td>
                                <td>
                                    <asp:Label ID="latitudeLabel" runat="server" Text='<%# Bind("latitude") %>' />
                                </td>
                            </tr>
                            <tr>
                                <td>經度:</td>
                                <td>
                                    <asp:Label ID="longitudeLabel" runat="server" Text='<%# Bind("longitude") %>' />
                                </td>
                            </tr>
                        </table>
                        <br />
                    </ItemTemplate>
                </asp:FormView>
            </ContentTemplate>
        </asp:UpdatePanel>
        <br />
        <br />
        <br />
        <br />
        <br />
        <div id="player">
        </div>
        <br />
        <br />
        <br />
        <asp:SqlDataSource ID="placeSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT [tourId], [place], [flickrId], [latitude], [longitude] FROM [tour]"></asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
<script src="../JavaScript/youtubeJavaScript%20.js"></script>
<script type="text/javascript" src="https://www.youtube.com/iframe_api"></script>
