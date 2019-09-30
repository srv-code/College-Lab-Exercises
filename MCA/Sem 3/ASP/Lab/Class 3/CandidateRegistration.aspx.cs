using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Text.RegularExpressions;
using System.IO;
using System.Diagnostics;


public partial class CandidateRegistration : System.Web.UI.Page {
    protected void Page_Load(object sender, EventArgs e) {
        Debug.Print("[Page reloaded at {0}]", DateTime.Now.Millisecond);
    }

    protected void CustomValidator1_ServerValidate(object source, ServerValidateEventArgs args) {
        DateTime date;
        args.IsValid = DateTime.TryParse(args.Value, out date);
        Label_ProfilePicUploadError.Text = Label_ResumeUploadError.Text = ""; // reset error messages
    }

    readonly long uploadMaxSize = 1024 * 1024 * 4; // 4MB;
    readonly string serverSavePath = "~/uploads/";

    private bool uploadFile(FileUpload uploader, Label errorLabel, FileType uploadFileType, string serverFileName) {
        /* Conditions: 
         *      - Has selected a file? 
         *      - Is file image type?
         *      - Is size within limit?
         *      - File save name?
         */
        if (uploader.HasFile) {
            Debug.Print("File selected as {0}: {1}", serverFileName, uploader.FileName);
            string ext = Path.GetExtension(uploader.FileName);
            if (checkFileType(ext, uploadFileType)) {
                if (uploader.FileContent.Length <= uploadMaxSize) {
                    string savePath = MapPath(serverSavePath + serverFileName + ext);
                    uploader.SaveAs(savePath);
                    Debug.Print("File saved in server, path: {0}", savePath);
                } else {
                    errorLabel.Text = "Error: Maximum file upload size is 4MB";
                    return false;
                }
            } else {
                errorLabel.Text = "Error: Please upload "+ uploadFileType +" file";
                return false;
            }
        } else {
            errorLabel.Text = "Error: Upload required";
            return false;
        }

        return true;
    }

    protected void Button_Register_Click(object sender, EventArgs e) {
        if (!uploadFile(FileUpload_ProfilePicture, Label_ProfilePicUploadError, FileType.IMAGE, "profile_pic"))
            return;

        if (!uploadFile(FileUpload_Resume, Label_ResumeUploadError, FileType.DOCUMENT, "resume"))
            return;

        clearInputs();
        Label_SubmitSuccessMessage.Text = "Registration successful!";
        Debug.Print("Submitted successfully");
    }

    enum FileType { IMAGE, DOCUMENT };

    private bool checkFileType(string ext, FileType type) {
        switch (type) { 
            case FileType.IMAGE:
                switch (ext) { 
                    case ".png": 
                    case ".jpg":
                    case ".jpeg":
                        return true;
                    default:
                        return false;
                }

            case FileType.DOCUMENT:
                switch (ext) {
                    case ".doc":
                    case ".docx":
                    case ".pdf":
                        return true;
                    default:
                        return false;
                }
        }
        return false; // dummy
    }

    protected void Button_Reset_Click(object sender, EventArgs e) {
        clearInputs();
    }

    private void clearInputs() {
        Label_SubmitSuccessMessage.Text = "";
        TextBox_Name.Text = "";
        RadioButtonList_Gender.ClearSelection();
        TextBox_DOB.Text = "";
        TextBox_Email.Text = "";
        TextBox_Password.Text = "";
        TextBox_ConfirmPassword.Text = "";
        TextBox_Phone.Text = "";
        TextBox_Address.Text = "";
        DropDownList_Nationality.ClearSelection();
    }
}