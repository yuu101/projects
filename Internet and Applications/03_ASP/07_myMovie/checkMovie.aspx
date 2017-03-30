<%@ Page Language="C#" AutoEventWireup="true" CodeFile="checkMovie.aspx.cs" Inherits="_03_ASP_07_myMovie_checkMovie" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Check</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />

    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            text-align: center;
            white-space: nowrap;
            height: 20px;
        }
    </style>

</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <div>
            <span class="title">訂單確認</span><br />
            <br />
            <table class="auto-style1">
                <tr>
                    <td class="auto-style2">電影名稱：</td>
                    <td class="tableContent">
                        <asp:Label ID="titleLabel" runat="server" Text="Label"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td class="tableHead">Movie：</td>
                    <td class="tableContent">
                        <asp:Label ID="engLabel" runat="server" Text="Label"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td class="tableHead">票價：</td>
                    <td class="tableContent">
                        <asp:Label ID="priceLabel" runat="server" Text="Label"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td class="tableHead">張數：</td>
                    <td class="tableContent">
                        <asp:Label ID="ticketsLabel" runat="server" Text="Label"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td class="tableHead">總價：</td>
                    <td class="tableContent">
                        <asp:Label ID="totalLabel" runat="server" Text="Label"></asp:Label>
                    </td>
                </tr>
            </table>
        </div>
    
    </div>
    </form>
</body>
</html>
