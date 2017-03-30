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
public class Service
{
	// 若要使用 HTTP GET，請加入 [WebGet] 屬性 (預設的 ResponseFormat 為 WebMessageFormat.Json)。
	// 若要建立可傳回 XML 的作業，
	//     請加入 [WebGet(ResponseFormat=WebMessageFormat.Xml)]，
	//     並在作業主體中包含下列這行程式:
	//         WebOperationContext.Current.OutgoingResponse.ContentType = "text/xml";
	[OperationContract]
	public void DoWork()
	{
		// 在此新增您的作業實作
		return;
	}

	// 在此新增其他作業，並以 [OperationContract] 來標示它們
}
