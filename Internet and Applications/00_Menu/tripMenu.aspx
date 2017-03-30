<%@ Page Language="C#" AutoEventWireup="true" CodeFile="tripMenu.aspx.cs" Inherits="_00_Menu_tripMenu" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:TreeView ID="TreeView1" runat="server" ImageSet="Arrows">
            <HoverNodeStyle Font-Underline="True" ForeColor="#5555DD" />
            <Nodes>
                <asp:TreeNode Expanded="False" SelectAction="Expand" Text="01_HTML" Value="01_HTML">
                    <asp:TreeNode NavigateUrl="~/01_html/Hello.html" Target="mainFrame" Text="HelloHTML" Value="HelloHTML"></asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Expanded="False" SelectAction="Expand" Text="02_JavaScript" Value="02_JavaScript">
                    <asp:TreeNode NavigateUrl="~/02_Javascript/simpleMedia.html" Target="mainFrame" Text="simpleMedia" Value="新節點"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/02_Javascript/youtubeMedia.html" Target="mainFrame" Text="youtubeMedia" Value="新節點"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/02_Javascript/09_homework/simpleMovie1.aspx" Target="mainFrame" Text="simpleMovie" Value="新節點"></asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Expanded="False" SelectAction="Expand" Text="03_ASP" Value="03_ASP">
                    <asp:TreeNode NavigateUrl="~/03_ASP/01_simple/simpleTrip.aspx" Target="mainFrame" Text="01_simple" Value="01_simple"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/03_ASP/02_youtubeSimple/youtubeTrip.aspx" Target="mainFrame" Text="02_youtube" Value="02_youtube"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/03_ASP/03_image/imageTrip.aspx" Target="mainFrame" Text="03_image" Value="03_image"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/03_ASP/04_flickr/flickrTrip.aspx" Target="mainFrame" Text="04_flilckr" Value="04_flilckr"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/03_ASP/05_calendar/calendarTrip.aspx" Target="mainFrame" Text="05_calendar" Value="05_calendar"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/03_ASP/06_price/priceTrip.aspx" Target="mainFrame" Text="06_price" Value="06_price"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/03_ASP/07_myMovie/myMovie.aspx" Target="mainFrame" Text="07_myMovie" Value="07_myMovie"></asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Expanded="False" SelectAction="Expand" Text="04_Database" Value="04_Database">
                    <asp:TreeNode Expanded="False" SelectAction="Expand" Text="admin" Value="admin">
                        <asp:TreeNode NavigateUrl="~/04_Database/admin/tour.aspx" Target="mainFrame" Text="tour" Value="tour"></asp:TreeNode>
                        <asp:TreeNode NavigateUrl="~/04_Database/admin/hotTours.aspx" Target="mainFrame" Text="hotTours" Value="hotTours"></asp:TreeNode>
                        <asp:TreeNode NavigateUrl="~/04_Database/admin/keyBuyers.aspx" Target="mainFrame" Text="keyBuyers" Value="keyBuyers"></asp:TreeNode>
                    </asp:TreeNode>
                    <asp:TreeNode Expanded="False" SelectAction="Expand" Text="store" Value="store">
                        <asp:TreeNode NavigateUrl="~/04_Database/store/Trip.aspx" Target="mainFrame" Text="trip" Value="trip"></asp:TreeNode>
                    </asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Expanded="False" SelectAction="Expand" Text="05_Midterm" Value="05_Midterm">
                    <asp:TreeNode Expanded="False" SelectAction="Expand" Text="051_Test(I) 0406" Value="新節點">
                        <asp:TreeNode Target="mainFrame" Text="10_season" Value="新節點" NavigateUrl="~/05_Midterm/051_Test(I) 0406/10_season.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="21_seasonPoll1" Value="21_seasonPoll1" NavigateUrl="~/05_Midterm/051_Test(I) 0406/21_seasonPoll1.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="22_seasonPoll2" Value="22_seasonPoll2" NavigateUrl="~/05_Midterm/051_Test(I) 0406/22_seasonPoll2.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="23_pollGrid1" Value="23_pollGrid1" NavigateUrl="~/05_Midterm/051_Test(I) 0406/23_pollGrid1.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="24_pollChart" Value="24_pollChart" NavigateUrl="~/05_Midterm/051_Test(I) 0406/24_pollChart.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="25_pollDataList" Value="25_pollDataList" NavigateUrl="~/05_Midterm/051_Test(I) 0406/25_pollDataList.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="31_seasonPoll3" Value="31_seasonPoll3" NavigateUrl="~/05_Midterm/051_Test(I) 0406/31_seasonPoll3.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="32_pollGrid2" Value="32_pollGrid2" NavigateUrl="~/05_Midterm/051_Test(I) 0406/32_pollGrid2.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="40_pollGrid3" Value="40_pollGrid3" NavigateUrl="~/05_Midterm/051_Test(I) 0406/40_pollGrid3.aspx"></asp:TreeNode>
                    </asp:TreeNode>
                    <asp:TreeNode Expanded="False" SelectAction="Expand" Text="052_Test(II) 0412" Value="新節點">
                        <asp:TreeNode Target="mainFrame" Text="11_movie" Value="11_movie" NavigateUrl="~/05_Midterm/052_Test(II) 0412/10_movie.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="21_movieGrade1" Value="21_movieGrade1" NavigateUrl="~/05_Midterm/052_Test(II) 0412/21_movieGrade1.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="22_movieGrade2" Value="22_movieGrade2" NavigateUrl="~/05_Midterm/052_Test(II) 0412/22_movieGrade2.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="23_gradeGrid1" Value="23_gradeGrid1" NavigateUrl="~/05_Midterm/052_Test(II) 0412/23_gradeGrid1.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="24_gradeChart" Value="24_gradeChart" NavigateUrl="~/05_Midterm/052_Test(II) 0412/24_gradeChart.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="25_gradeDataList" Value="25_gradeDataList" NavigateUrl="~/05_Midterm/052_Test(II) 0412/25_gradeDataList.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="31_movieGrade3" Value="31_movieGrade3" NavigateUrl="~/05_Midterm/052_Test(II) 0412/31_movieGrade3.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="32_gradeGrid2" Value="32_gradeGrid2" NavigateUrl="~/05_Midterm/052_Test(II) 0412/32_gradeGrid2.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="41_gradeGrid3" Value="41_gradeGrid3" NavigateUrl="~/05_Midterm/052_Test(II) 0412/41_gradeGrid3.aspx"></asp:TreeNode>
                    </asp:TreeNode>
                    <asp:TreeNode Expanded="False" SelectAction="Expand" Text="053_Exam(I) 0419" Value="新節點">
                        <asp:TreeNode Target="mainFrame" Text="11_simpleBuy" Value="11_simpleBuy" NavigateUrl="~/05_Midterm/053_Exam(I) 0419/11_simpleBuy.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="12_imageBuy" Value="12_imageBuy" NavigateUrl="~/05_Midterm/053_Exam(I) 0419/12_imageBuy.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="13_salesGrid" Value="13_salesGrid" NavigateUrl="~/05_Midterm/053_Exam(I) 0419/13_salesGrid.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="21_revenueGrid" Value="21_revenueGrid" NavigateUrl="~/05_Midterm/053_Exam(I) 0419/21_revenueGrid.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="22_salesChart" Value="22_salesChart" NavigateUrl="~/05_Midterm/053_Exam(I) 0419/22_salesChart.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="23_salesDataList" Value="23_salesDataList" NavigateUrl="~/05_Midterm/053_Exam(I) 0419/23_salesDataList.aspx"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="24_bestSales" Value="24_bestSales" NavigateUrl="~/05_Midterm/053_Exam(I) 0419/24_bestSales.aspx"></asp:TreeNode>
                    </asp:TreeNode>
                    <asp:TreeNode Expanded="False" SelectAction="Expand" Text="054_Exam(II)" Value="新節點">
                        <asp:TreeNode Target="mainFrame" Text="新節點" Value="新節點"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="新節點" Value="新節點"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="新節點" Value="新節點"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="新節點" Value="新節點"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="新節點" Value="新節點"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="新節點" Value="新節點"></asp:TreeNode>
                        <asp:TreeNode Target="mainFrame" Text="新節點" Value="新節點"></asp:TreeNode>
                    </asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Expanded="False" SelectAction="Expand" Text="06_AJAX" Value="06_AJAX">
                    <asp:TreeNode Target="mainFrame" Text="trip" Value="trip" NavigateUrl="~/04_Database/store/Trip.aspx"></asp:TreeNode>
                    <asp:TreeNode Target="mainFrame" Text="ajaxTrip" Value="ajaxTrip" NavigateUrl="~/06_AJAX/store/ajaxTrip.aspx"></asp:TreeNode>
                    <asp:TreeNode Target="mainFrame" Text="whyAjax" Value="whyAjax" NavigateUrl="~/06_AJAX/vote/ajaxVote.aspx"></asp:TreeNode>
                    <asp:TreeNode Target="mainFrame" Text="ajaxVote" Value="ajaxVote" NavigateUrl="~/06_AJAX/vote/ajaxVoteReal.aspx"></asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Expanded="False" SelectAction="Expand" Text="07_WebService" Value="07_WebService">
                    <asp:TreeNode NavigateUrl="~/07_WebService/tour.aspx" Target="mainFrame" Text="tour" Value="tour"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/07_WebService/aspLocation.aspx" Target="mainFrame" Text="aspLocation" Value="aspLocation"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/07_WebService/ajaxLocation.aspx" Target="mainFrame" Text="ajaxLocation" Value="ajaxLocation"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/07_WebService/wcfLocation.aspx" Target="mainFrame" Text="wcfLocation" Value="wcfLocation"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/07_WebService/jsLocation.aspx" Target="mainFrame" Text="jsLocation" Value="jsLocation"></asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Expanded="False" SelectAction="Expand" Text="08_GoogleMap" Value="08_GoogleMap">
                    <asp:TreeNode NavigateUrl="~/08_GoogleMap/helloMap.html" Target="mainFrame" Text="helloMap" Value="helloMap"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/08_GoogleMap/wsMap.aspx" Target="mainFrame" Text="wsMap" Value="wsMap"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/08_GoogleMap/helloStreetView.html" Target="mainFrame" Text="helloStreetView" Value="helloStreetView"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/08_GoogleMap/wsStreetView.aspx" Target="mainFrame" Text="wsStreetView" Value="wsStreetView"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/08_GoogleMap/googleMap.aspx" Target="mainFrame" Text="googleMap" Value="googleMap"></asp:TreeNode>
                    <asp:TreeNode NavigateUrl="~/08_GoogleMap/googleDirection.aspx" Target="mainFrame" Text="googleDirection" Value="googleDirection"></asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Expanded="False" SelectAction="Expand" Text="09_YouTravel" Value="09_YouTravel">
                    <asp:TreeNode Expanded="False" SelectAction="Expand" Text="geocoder" Value="geocoder">
                        <asp:TreeNode NavigateUrl="~/09_YouTravel/geocoder/locationMap.aspx" Target="mainFrame" Text="locationMap" Value="locationMap"></asp:TreeNode>
                    </asp:TreeNode>
                    <asp:TreeNode Expanded="False" SelectAction="Expand" Text="admin" Value="admin">
                        <asp:TreeNode NavigateUrl="~/09_YouTravel/admin/tour.aspx" Target="mainFrame" Text="tour" Value="tour"></asp:TreeNode>
                    </asp:TreeNode>
                    <asp:TreeNode Expanded="False" SelectAction="Expand" Text="mail" Value="mail">
                        <asp:TreeNode NavigateUrl="~/09_YouTravel/mail/simpleMail.aspx" Target="mainFrame" Text="simpleMail" Value="simpleMail"></asp:TreeNode>
                    </asp:TreeNode>
                    <asp:TreeNode Expanded="False" SelectAction="Expand" Text="store" Value="store">
                        <asp:TreeNode NavigateUrl="~/09_YouTravel/store/Trip.aspx" Target="mainFrame" Text="trip" Value="trip"></asp:TreeNode>
                    </asp:TreeNode>
                </asp:TreeNode>
                <asp:TreeNode Expanded="False" SelectAction="Expand" Text="10_FB" Value="10_FB">
                    <asp:TreeNode NavigateUrl="~/10_Facebook/index.html" Target="_blank" Text="login" Value="login"></asp:TreeNode>
                </asp:TreeNode>
            </Nodes>
            <NodeStyle Font-Names="Tahoma" Font-Size="10pt" ForeColor="Black" HorizontalPadding="5px" NodeSpacing="0px" VerticalPadding="0px" />
            <ParentNodeStyle Font-Bold="False" />
            <SelectedNodeStyle Font-Underline="True" ForeColor="#5555DD" HorizontalPadding="0px" VerticalPadding="0px" />
        </asp:TreeView>
    
    </div>
    </form>
</body>
</html>
