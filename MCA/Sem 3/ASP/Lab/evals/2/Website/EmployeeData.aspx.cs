using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;

public partial class EmployeeData : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {}

	protected void DetailsView1_ItemInserting(object sender, DetailsViewInsertEventArgs e) {}

	protected void SqlDataSource_Employee_Inserting(object sender, SqlDataSourceCommandEventArgs e) {
		FileUpload uploader = (FileUpload)DetailsView1.FindControl("FileUpload1_1");
		string picPath = "~/uploads/images/profile_pics/" + uploader.FileName;
		uploader.SaveAs(MapPath(picPath));
		Debug.Print("picPath: {0}", picPath);
		e.Command.Parameters["@pic"].Value = picPath;
	}
}