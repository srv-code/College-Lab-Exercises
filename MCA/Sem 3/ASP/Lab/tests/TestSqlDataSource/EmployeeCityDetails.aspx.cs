using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;
using System.Drawing;


public partial class EmployeeCityDetails : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
	}

	protected void GridView1_RowCommand(object sender, GridViewCommandEventArgs e) {
		Debug.Print(" // invoked: GridView1_RowCommand, sender={0}, [new: username={1}]",
			sender, GridView1.FooterRow.FindControl("TextBox_NewUserName"));
		
        // insert a new row
        SqlDataSource_emp.InsertParameters["username"].DefaultValue = ((TextBox)GridView1.FooterRow.FindControl("TextBox_NewUserName")).Text;
        SqlDataSource_emp.InsertParameters["city"].DefaultValue = 
        SqlDataSource_emp.InsertParameters["designation"].DefaultValue = 
        int nrows = SqlDataSource_emp.Insert();

        if(nrows == 1) {
            Label_OperationStatus.Text = "1 row inserted successfully";
            Label_OperationStatus.BackColor = Color.Red;
        } else {
            Label_OperationStatus.Text = "Insertion failed! (" + nrows  + ")";
            Label_OperationStatus.BackColor = Color.Yellow;
        }
	}
}