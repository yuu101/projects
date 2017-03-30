using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _03_ASP_07_myMovie_myMovie : System.Web.UI.Page
{
    
    
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            titleLabel.Text = "玩命關頭7";
            subtitleLabel.Text = "玩命關頭7";
            engLabel.Text = "Fast & Furious 7";
            contentLabel.Text = "《玩命關頭7》由導演溫子仁首度執導，還有觀眾喜愛的蜜雪兒羅卓奎茲、喬丹娜布魯斯特、泰瑞斯吉布森、路達克里斯、艾兒莎巴塔奇、盧卡斯布萊克以及新加入的角色包括傑森史塔森、吉蒙翰蘇、東尼嘉、龍達魯西和寇特羅素。尼爾莫瑞茲、馮迪索和麥可佛瑞爾參與幕後製片，克里斯摩根為此片編劇。";
            timeLabel.Text = "2時18分";
            priceLabel.Text = "300";

            ticketsTextBox.Text = "1";

            totalLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(priceLabel.Text) * Convert.ToInt32(ticketsTextBox.Text)));
            youtubeIdHiddenField.Value = "cRtY5PdyrTM";
        }
    }
    
    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {

        titleLabel.Text = "分歧者2：叛亂者";
        subtitleLabel.Text = "分歧者2：叛亂者";
        engLabel.Text = "Divergent Series：Insurgent";
        contentLabel.Text = "在躲過追殺後，翠絲和托比亞等一行人逃往友好派尋求協助，雖然明知不可能永遠躲避下去，但她好希望有那麼一次，讓別人去肩負重任，因為她已經筋疲力盡，似乎再也無法擔任那個揭開陰謀、領導革命的人。而在這趟充滿猜疑與危險的逃亡之路上，她以為自己對於背叛已司空見慣，但翠絲怎麼也沒想到，與她關係最密切、感情最親近的他，竟然是一名背叛者。";
        timeLabel.Text = "1時59分";
        priceLabel.Text = "200";

        totalLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(priceLabel.Text) * Convert.ToInt32(ticketsTextBox.Text)));
        youtubeIdHiddenField.Value = "FhbCu501Dxw";
     
    }
    protected void ImageButton2_Click(object sender, ImageClickEventArgs e)
    {
        titleLabel.Text = "復仇者聯盟2：奧創紀元";
        subtitleLabel.Text = "復仇者聯盟2：奧創紀元";
        engLabel.Text = "Avengers：Age of Ultron";
        contentLabel.Text = "東尼史塔克為了維護地球的和平安全，嘗試啟動一個機密的計畫，然而卻發生了無法想像的錯誤，使得地球上最強的超級英雄，包括鋼鐵人、美國隊長、雷神索爾、綠巨人浩克、黑寡婦以及鷹眼，陷入事關全球命運動盪不安的終極考驗。當邪惡的奧創出現，唯有復仇者聯盟能夠阻止它進行它的恐怖計畫，這群超級英雄將面臨難以預測的危機，並展開它們史詩級的壯闊冒險。";
        timeLabel.Text = "尚未公布";
        priceLabel.Text = "250";

        totalLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(priceLabel.Text) * Convert.ToInt32(ticketsTextBox.Text)));
        youtubeIdHiddenField.Value = "uSLculV2HWk";
    }
    protected void ImageButton3_Click(object sender, ImageClickEventArgs e)
    {
        titleLabel.Text = "玩命關頭7";
        subtitleLabel.Text = "玩命關頭7";
        engLabel.Text = "Fast & Furious 7";
        contentLabel.Text = "《玩命關頭7》由導演溫子仁首度執導，還有觀眾喜愛的蜜雪兒羅卓奎茲、喬丹娜布魯斯特、泰瑞斯吉布森、路達克里斯、艾兒莎巴塔奇、盧卡斯布萊克以及新加入的角色包括傑森史塔森、吉蒙翰蘇、東尼嘉、龍達魯西和寇特羅素。尼爾莫瑞茲、馮迪索和麥可佛瑞爾參與幕後製片，克里斯摩根為此片編劇。";
        timeLabel.Text = "2時18分";
        priceLabel.Text = "300";

        totalLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(priceLabel.Text) * Convert.ToInt32(ticketsTextBox.Text)));
        youtubeIdHiddenField.Value = "cRtY5PdyrTM";
    }
    protected void ticketsTextBox_OnTextChanged(object sender, EventArgs e)
    {
        totalLabel.Text = string.Format("{0:N0}", (Convert.ToInt32(priceLabel.Text) * Convert.ToInt32(ticketsTextBox.Text)));
    }
    protected void goButton_Click(object sender, EventArgs e)
    {
        Session["title"] = titleLabel.Text;
        Session["eng"] = engLabel.Text;
        Session["price"] = priceLabel.Text;
        Session["tickets"] = ticketsTextBox.Text;
        Session["total"] = totalLabel.Text;

        Response.Redirect("checkMovie.aspx");
    }
}