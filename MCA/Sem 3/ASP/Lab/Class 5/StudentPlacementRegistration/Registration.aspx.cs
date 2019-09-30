using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;
using System.Drawing;

public partial class Registration : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
		if (!Page.IsPostBack) {
			Wizard_Registration.ActiveStepIndex = 0;
		}
    }

	protected void LinkButton_ShowCalendar_Click(object sender, EventArgs e) {
		Calendar_DOB.Visible = true;
	}

	protected void Calendar_DOB_SelectionChanged(object sender, EventArgs e) {
		TextBox_DOB.Text = Calendar_DOB.SelectedDate.ToShortDateString();
		Calendar_DOB.Visible = false;
	}

	protected void Wizard_Registration_FinishButtonClick(object sender, WizardNavigationEventArgs e) {
		Debug.Print("invoked: Wizard_Registration_FinishButtonClick");
		Debug.Print("inserting data...");
		// Debug.Print("name={0}, ach={1}", TextBox_Name.Text, TextBox_Achievements.Text);
		SqlDataSource_Student.InsertParameters["name"].DefaultValue = TextBox_Name.Text;
		SqlDataSource_Student.InsertParameters["gender"].DefaultValue = RadioButtonList_Gender.SelectedValue.Substring(0, 1).ToUpper();
		// SqlDataSource_Student.InsertParameters["date"].DefaultValue = TextBox_DOB.Text;
		SqlDataSource_Student.InsertParameters["address"].DefaultValue = TextBox_Address.Text;
		SqlDataSource_Student.InsertParameters["marks_10"].DefaultValue = TextBox_Marks10th.Text;
		SqlDataSource_Student.InsertParameters["marks_12"].DefaultValue = TextBox_Marks12th.Text;
		SqlDataSource_Student.InsertParameters["grade_ug"].DefaultValue = TextBox_GradeUG.Text;
		SqlDataSource_Student.InsertParameters["grade_pg"].DefaultValue = TextBox_GradePG.Text;
		SqlDataSource_Student.InsertParameters["achievement"].DefaultValue = TextBox_Achievements.Text;
		SqlDataSource_Student.InsertParameters["reference1"].DefaultValue = TextBox_Reference1.Text;
		SqlDataSource_Student.InsertParameters["reference2"].DefaultValue = TextBox_Reference2.Text;
		SqlDataSource_Student.InsertParameters["reference3"].DefaultValue = TextBox_Reference3.Text;
		int rows = SqlDataSource_Student.Insert();
		Debug.Print("inserted: rows={0}", rows);
		if (rows > 0) {
			Label_InsertionStatus.Text = "Data submitted successfully";
			Label_InsertionStatus.BackColor = Color.Green;
			LinkButton_GotoRegistrationDataPage.Enabled = true;
		} else {
			Label_InsertionStatus.Text = "Cannot insert data!";
			Label_InsertionStatus.BackColor = Color.Red;
			LinkButton_GotoRegistrationDataPage.Enabled = false;
		}
	}
}