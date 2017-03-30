<%@ Page Language="C#" AutoEventWireup="true" CodeFile="priceTrip.aspx.cs" Inherits="_03_ASP_06_price_priceTrip" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>price Trip</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
    <style type="text/css">
        .auto-style1 {
            width: 100%;
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
                    <asp:RadioButtonList ID="placeRadioButtonList" runat="server" RepeatDirection="Horizontal" CssClass="formViewContent" AutoPostBack="True" OnSelectedIndexChanged="placeRadioButtonList_SelectedIndexChanged">
                        <asp:ListItem Selected="True" Value="1">東京</asp:ListItem>
                        <asp:ListItem Value="2">紐約</asp:ListItem>
                        <asp:ListItem Value="3">倫敦</asp:ListItem>
                    </asp:RadioButtonList>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <br />
        <asp:Image ID="placeImage" runat="server" />
        <br />
        <br />
        <table class="auto-style1">
            <tr>
                <td>單價：</td>
                <td>
                    <asp:Label ID="priceLabel" runat="server" CssClass="tableHead" Text="Label"></asp:Label>
                </td>
            </tr>
            <tr>
                <td>天數：</td>
                <td>
                    <asp:TextBox ID="daysTextBox" runat="server" AutoPostBack="True" CssClass="tableContent" OnTextChanged="daysTextBox_OnTextChanged"></asp:TextBox>
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
        <asp:Calendar ID="tripCalendar" runat="server" BackColor="White" BorderColor="White" BorderWidth="1px" Font-Names="Verdana" Font-Size="9pt" ForeColor="Black" Height="190px" NextPrevFormat="FullMonth" Width="350px">
            <DayHeaderStyle Font-Bold="True" Font-Size="8pt" />
            <NextPrevStyle Font-Bold="True" Font-Size="8pt" ForeColor="#333333" VerticalAlign="Bottom" />
            <OtherMonthDayStyle ForeColor="#999999" />
            <SelectedDayStyle BackColor="#333399" ForeColor="White" />
            <TitleStyle BackColor="White" BorderColor="Black" BorderWidth="4px" Font-Bold="True" Font-Size="12pt" ForeColor="#333399" />
            <TodayDayStyle BackColor="#CCCCCC" />
        </asp:Calendar>
        <br />
        <br />
        <br />
        <asp:Button ID="goButton" runat="server" Text="走吧" OnClick="goButton_Click" />
        <br />
    
    </div>
        <asp:HiddenField ID="youtubeIdHiddenField" runat="server" />
        <asp:HiddenField ID="priceHiddenField" runat="server" />
    </form>
    </body>
</html>
