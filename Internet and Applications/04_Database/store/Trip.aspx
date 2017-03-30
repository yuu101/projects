<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Trip.aspx.cs" Inherits="_04_Datebase_store_Trip" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>price Trip</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />

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
                    <asp:RadioButtonList ID="placeRadioButtonList" runat="server" RepeatDirection="Horizontal" CssClass="formViewContent" AutoPostBack="True" OnSelectedIndexChanged="placeRadioButtonList_SelectedIndexChanged" DataSourceID="tourSqlDataSource" DataTextField="place" DataValueField="tourId">
                        <asp:ListItem Selected="True" Value="1">東京</asp:ListItem>
                        <asp:ListItem Value="2">紐約</asp:ListItem>
                        <asp:ListItem Value="3">倫敦</asp:ListItem>
                    </asp:RadioButtonList>
                </td>
            </tr>
        </table>
        <br />
        <asp:FormView ID="placeFormView" runat="server" DataKeyNames="tourId" DataSourceID="tourSqlDataSource" OnDataBound="placeFormView_DataBound">
            <EditItemTemplate>
                tourId:
                <asp:Label ID="tourIdLabel1" runat="server" Text='<%# Eval("tourId") %>' />
                <br />
                place:
                <asp:TextBox ID="placeTextBox" runat="server" Text='<%# Bind("place") %>' />
                <br />
                price:
                <asp:TextBox ID="priceTextBox" runat="server" Text='<%# Bind("price") %>' />
                <br />
                flickrId:
                <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                <br />
                youtubeId:
                <asp:TextBox ID="youtubeIdTextBox" runat="server" Text='<%# Bind("youtubeId") %>' />
                <br />
                <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="更新" />
                &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
            </EditItemTemplate>
            <InsertItemTemplate>
                place:
                <asp:TextBox ID="placeTextBox" runat="server" Text='<%# Bind("place") %>' />
                <br />
                price:
                <asp:TextBox ID="priceTextBox" runat="server" Text='<%# Bind("price") %>' />
                <br />
                flickrId:
                <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                <br />
                youtubeId:
                <asp:TextBox ID="youtubeIdTextBox" runat="server" Text='<%# Bind("youtubeId") %>' />
                <br />
                <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="插入" />
                &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
            </InsertItemTemplate>
            <ItemTemplate>
                <asp:Image ID="placeImage" runat="server" ImageUrl='<%# Eval("flickrId","http://farm9.staticflickr.com/{0}") %>' />
                <br />
                <br />
                <table>
                    <tr>
                        <td>單價：</td>
                        <td>
                            <asp:Label ID="priceLabel" runat="server" Text='<%# Bind("price") %>' />
                        </td>
                    </tr>
                </table>
                <asp:HiddenField ID="priceHiddenField" runat="server" Value='<%# Eval("price") %>' />
                <asp:HiddenField ID="youtubeIdHiddenField" runat="server" Value='<%# Eval("youtubeId") %>' />
            </ItemTemplate>
        </asp:FormView>
        <br />
        <br />
        <br />
        <br />
        <table class="auto-style1">
            <tr>
                <td>天數：</td>
                <td>
                    <asp:TextBox ID="daysTextBox" runat="server" AutoPostBack="True" CssClass="tableContent" TextChanged="daysTextBox_TextChanged" OnTextChanged="daysTextBox_TextChanged"></asp:TextBox>
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
        <asp:HiddenField ID="totalHiddenField" runat="server" />
        <asp:SqlDataSource ID="tourSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT * FROM [tour]"></asp:SqlDataSource>
        <br />
        <br />
        <br />
        <br />
    </form>
    </body>
</html>
