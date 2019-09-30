using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Text;

public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
        // clearFormControls();
    }

    protected void Button_Submit_Click(object sender, EventArgs e) {        
        showSelectionData();
        clearFormControls();
    }

    private void clearFormControls() {
        // TextBox_SubmittedData.Text = "";
        ListBox_AirlinesCompany.ClearSelection();
        RadioButtonList_Grading.ClearSelection();
    }

    private void showSelectionData() {
        StringBuilder res = new StringBuilder();
        res.Append("Airline Company: ")
                .Append(ListBox_AirlinesCompany.SelectedValue)
                .AppendLine()
            .Append("Grading: ")
                .Append(RadioButtonList_Grading.SelectedValue);
        TextBox_SubmittedData.Text = res.ToString();
        TextBox_SubmittedData.Visible = true;
    }
}