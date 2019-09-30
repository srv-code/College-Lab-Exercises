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

    private const long uploadMaxSize = 1024 * 100; // 100 KB;
    private const string serverSavePath = "~/uploads/";

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

        if (!validatePassword())
            return;

        showSubmittedData();
        Debug.Print("Submitted successfully");
        clearInputs();
        Label_SubmitSuccessMessage.Text = "Registration successful!";
    }

    private void showSubmittedData() {
        Debug.Print("name={0}, gender={1}, dob={2}, email={3}, pwd={4}, cpwd={5}, ph={6}, addr={7}, " +
            "nat={8}, pic={9}, resume={10}",
            TextBox_Name.Text,
            RadioButtonList_Gender.Text,
            TextBox_DOB.Text,
            TextBox_Email.Text,
            TextBox_Password.Text,
            TextBox_ConfirmPassword.Text,
            TextBox_Phone.Text,
            TextBox_Address.Text,
            DropDownList_Nationality.SelectedValue,
            FileUpload_ProfilePicture.FileName,
            FileUpload_Resume.FileName);
    }

    private bool validatePassword() {
        char[] pwd = TextBox_Password.Text.ToCharArray();
        if (pwd.Length == 13 &&
            Char.IsLetterOrDigit(pwd[0]) && Char.IsLetterOrDigit(pwd[pwd.Length - 1])) {
                Label_PasswordPolicyError.Visible = false;
                return true;
        }
        Label_PasswordPolicyError.Visible = true;
        return false;
    }

    enum FileType { IMAGE, DOCUMENT };

    private bool checkFileType(string ext, FileType type) {
        switch (type) { 
            case FileType.IMAGE:
                switch (ext) { 
                    // case ".png": 
                    case ".jpg":
                    case ".gif":
                    // case ".jpeg":
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
        Calendar_DOB.VisibleDate = DateTime.Today;
        Calendar_DOB.SelectedDates.Clear();
        Calendar_DOB.Visible = false;
        TextBox_DOB.Text = "";
        Label_PasswordPolicyError.Visible = false;
        Label_SubmitSuccessMessage.Text = "";
        TextBox_Name.Text = "";
        RadioButtonList_Gender.ClearSelection();
        TextBox_Email.Text = "";
        TextBox_Password.Text = "";
        TextBox_ConfirmPassword.Text = "";
        TextBox_Phone.Text = "";
        TextBox_Address.Text = "";
        DropDownList_Nationality.ClearSelection();
    }

    // private const int lastPermissibleYear = DateTime.Now.Year - 18; // minimum age is 18
    private int lastPermissibleYear = DateTime.Now.Year - 1; // minimum age is 1

    protected void Calendar_DOB_DayRender(object sender, DayRenderEventArgs e) {
        if(e.Day.Date.Year <= lastPermissibleYear) {
            e.Day.IsSelectable = true;
            e.Cell.BackColor = System.Drawing.Color.LightBlue;
        } else {
            e.Day.IsSelectable = false;
            e.Cell.BackColor = System.Drawing.Color.Gray;
        }
    }

    protected void Button_SelectDob_Click(object sender, EventArgs e) {
        Calendar_DOB.Visible = true;
    }

    protected void Calendar_DOB_SelectionChanged(object sender, EventArgs e) {
        Debug.Print("DOB selected: " + Calendar_DOB.SelectedDate.ToShortDateString());
        TextBox_DOB.Text = Calendar_DOB.SelectedDate.ToShortDateString();
        Calendar_DOB.Visible = false;
    }
}