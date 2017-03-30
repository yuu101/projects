using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Activation;
using System.ServiceModel.Web;
using System.Text;

[ServiceContract(Namespace = "")]
[AspNetCompatibilityRequirements(RequirementsMode = AspNetCompatibilityRequirementsMode.Allowed)]
public class LocationService
{
    // 若要使用 HTTP GET，請加入 [WebGet] 屬性 (預設的 ResponseFormat 為 WebMessageFormat.Json)。
    // 若要建立可傳回 XML 的作業，
    //     請加入 [WebGet(ResponseFormat=WebMessageFormat.Xml)]，
    //     並在作業主體中包含下列這行程式:
    //         WebOperationContext.Current.OutgoingResponse.ContentType = "text/xml";
    [OperationContract]
    [WebGet]
    public PlaceData getLocation(int placeId)
    {
        tourDataSetTableAdapters.tourTableAdapter tourTableAdapter = new tourDataSetTableAdapters.tourTableAdapter();

        tourDataSet.tourDataTable dataTable = tourTableAdapter.getLocation(placeId);

        tourDataSet.tourRow dataRow = (tourDataSet.tourRow)dataTable.Rows[0];

        PlaceData placeData = new PlaceData();

        placeData.price = Convert.ToInt16(dataRow.price);
        placeData.youtubeId = dataRow.youtubeId;
        placeData.flickrId = dataRow.flickrId;
        placeData.latitude = Convert.ToSingle(dataRow.latitude);
        placeData.longitude = Convert.ToSingle(dataRow.longitude);

        return placeData;

    }

    // 在此新增其他作業，並以 [OperationContract] 來標示它們
    public class PlaceData
    {
        public int price;
        public String youtubeId;
        public String flickrId;
        public Single latitude;
        public Single longitude;
    }
}
