using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;
using System.Diagnostics;

public partial class TeachersDayCelebration : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
		Debug.Print("---------[Page_Load]---------");
    }

	readonly string serverSavePath = "~/Images/";

	protected void Button_Upload_Click(object sender, EventArgs e) {
		string fileName = FileUpload_NewPhoto.FileName;
		switch (Path.GetExtension(fileName)) { 
			case ".png":
			case ".jpg":
			case ".jpeg":
			case ".gif":
				break;
			default:
				Label_UploadError.Text = "Select an image file!";
				return;
		}

		string filePath = serverSavePath + fileName;
		FileUpload_NewPhoto.SaveAs(MapPath(filePath));
		Debug.Print("file uploaded: {0}", filePath);

		SqlDataSource_Images.InsertParameters["name"].DefaultValue = TextBox_NewName.Text;
		SqlDataSource_Images.InsertParameters["storage_path"].DefaultValue = filePath;
		SqlDataSource_Images.InsertParameters["description"].DefaultValue = TextBox_NewDescription.Text;
		if (SqlDataSource_Images.Insert() != 1) {
			Label_UploadError.Text = "Cannot insert data into database!";
			return;
		}
		clearInputs();
		Debug.Print("inserted to db");
	}

	protected void Button_Cancel_Click(object sender, EventArgs e) {
		clearInputs();
	}

	private void clearInputs() {
		TextBox_NewName.Text = 
			TextBox_NewDescription.Text = 
				Label_UploadError.Text = String.Empty;
	}
}