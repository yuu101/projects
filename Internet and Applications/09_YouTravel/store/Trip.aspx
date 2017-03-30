<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Trip.aspx.cs" Inherits="_09_YouTravel_store_Trip" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>price Trip</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
    <link href="../../Styles/datepicker.css" rel="stylesheet" />
    <style type="text/css">
        .auto-style1 {
            height: 20px;
        }
    </style>

</head>

<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">我要去旅行</span><br />
        <br />
        <table>
            <tr>
                <td><span class="tableHead">旅行者：</span> </td>
                <td>
                    <asp:TextBox ID="userTextBox" runat="server" CssClass="tableContent"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="userTextBox" Display="Dynamic" ErrorMessage="請輸入姓名!" ForeColor="#FF0066"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td><span class="tableHead">旅行地：</span> </td>
                <td>
                    <asp:RadioButtonList ID="placeRadioButtonList" runat="server" RepeatDirection="Horizontal" CssClass="formViewContent" DataSourceID="tourSqlDataSource" DataTextField="place" DataValueField="tourId" OnDataBound="placeRadioButtonList_DataBound">
                        <asp:ListItem Selected="True" Value="1">東京</asp:ListItem>
                        <asp:ListItem Value="2">紐約</asp:ListItem>
                        <asp:ListItem Value="3">倫敦</asp:ListItem>
                    </asp:RadioButtonList>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <asp:Image ID="placeImage" runat="server" />
        <br />
        <br />
        <br />
        <table class="auto-style1">
            <tr>
                <td>單價：</td>
                <td>
                    <asp:Label ID="priceLabel" runat="server" CssClass="tableContent" Text="Label"></asp:Label>
                </td>
            </tr>
            <tr>
                <td>天數：</td>
                <td>
                    <asp:TextBox ID="daysTextBox" runat="server" CssClass="tableContent" onblur="calculateTotal()" TextChanged="daysTextBox_TextChanged"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td>總價：</td>
                <td>
                    <asp:Label ID="totalLabel" runat="server" CssClass="tableContent" Text="Label"></asp:Label>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <br />
        <div id="calendarCanvas">
        </div>
        <br />
        <br />
        <br />
        <asp:Button ID="goButton" runat="server" Text="走吧" OnClick="goButton_Click" />
        <br />
    
    </div>
        <asp:HiddenField ID="totalHiddenField" runat="server" />
        <asp:SqlDataSource ID="tourSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT * FROM [tour]"></asp:SqlDataSource>
        <asp:HiddenField ID="youtubeIdHiddenField" runat="server" />
        <asp:HiddenField ID="priceHiddenField" runat="server" />
        <asp:HiddenField ID="tripDateHiddenField" runat="server" />
        <asp:HiddenField ID="latitudeHiddenField" runat="server" />
        <asp:HiddenField ID="longitudeHiddenField" runat="server" />
        <br />
        <br />
        <br />
        <br />
    </form>
    </body>
</html>
<script src="../../Scripts/jquery-1.10.2.js"></script>
<script src="../../JavaScript/tripJQuery.js"></script>
<script src="../../JavaScript/datepicker.js"></script>
<script src="../../JavaScript/LocationService.js"></script>
