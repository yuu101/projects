<%@ Page Language="C#" AutoEventWireup="true" CodeFile="23_salesDataList.aspx.cs" Inherits="_05_Midterm_053_Exam_I__0419_23_salesDataList
" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Datalist    </title>
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
    
        <span class="title">銷售統計圖</span><br />
        <br />
        <br />
        <asp:RadioButtonList ID="RadioButtonList1" runat="server" AutoPostBack="True" DataSourceID="SqlDataSource1" DataTextField="category" DataValueField="categoryId" RepeatDirection="Horizontal">
        </asp:RadioButtonList>
        <br />
        <asp:DataList ID="DataList1" runat="server" DataSourceID="SqlDataSource2" RepeatDirection="Horizontal">
            <ItemTemplate>
                <asp:Label ID="productNameLabel0" runat="server" Text='<%# Eval("productName") %>' />
                <br />
                <asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("flickrId", "http://farm9.staticflickr.com/{0}") %>' />
                <br />
                <table class="auto-style1">
                    <tr>
                        <td>總量：</td>
                        <td>
                            <asp:Label ID="Expr1Label" runat="server" Text='<%# Eval("Expr1") %>' />
                        </td>
                    </tr>
                    <tr>
                        <td>總額：</td>
                        <td>
                            <asp:Label ID="Expr2Label" runat="server" Text='<%# Eval("Expr2") %>' />
                        </td>
                    </tr>
                </table>
<br />
            </ItemTemplate>
        </asp:DataList>
        <br />
        <br />
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:examConnectionString %>" SelectCommand="SELECT categoryId, category FROM product GROUP BY categoryId, category"></asp:SqlDataSource>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:examConnectionString %>" SelectCommand="SELECT SUM(sales.total) AS Expr1, COUNT(sales.amount) AS Expr2, product.categoryId, product.productName, product.flickrId FROM product INNER JOIN sales ON product.productId = sales.productId GROUP BY product.categoryId, product.productName, product.flickrId HAVING (product.categoryId = @categoryId)">
            <SelectParameters>
                <asp:ControlParameter ControlID="RadioButtonList1" DefaultValue="1" Name="categoryId" PropertyName="SelectedValue" />
            </SelectParameters>
        </asp:SqlDataSource>
        <br />
    
    </div>
    </form>
</body>
</html>
