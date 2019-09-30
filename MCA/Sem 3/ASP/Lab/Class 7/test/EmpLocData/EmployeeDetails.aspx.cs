using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Diagnostics;
using System.Drawing;


public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e) {
		Debug.Print("--------[Page_Load]--------");
    }

    protected void GridView1_RowCommand(object sender, GridViewCommandEventArgs e) {
        Debug.Print("invoked: GridView1_RowCommand");
        string newName = ((TextBox)GridView_EmpLoc.FooterRow.FindControl("TextBox_NewName")).Text;
		string newLocation = ((DropDownList)GridView_EmpLoc.FooterRow.FindControl("DropDownList_NewLocation")).SelectedValue;
        string newDesignation = ((TextBox)GridView_EmpLoc.FooterRow.FindControl("TextBox_NewDesignation")).Text;

        if (String.Empty.Equals(newName.Trim())) {
            Debug.Print("new name is empty, cannot insert tuple!");
            return;
        }

        SqlDataSource_Employees.InsertParameters["name"].DefaultValue = newName;
        SqlDataSource_Employees.InsertParameters["location"].DefaultValue = newLocation;
        SqlDataSource_Employees.InsertParameters["designation"].DefaultValue = newDesignation;
        Debug.Print("inserting data...");
        int nrows = SqlDataSource_Employees.Insert();
        if (nrows == 1) {
            Label_OperationStatus.Text = "New record inserted successfully";
            Label_OperationStatus.BackColor = Color.Yellow;
        } else {
            Label_OperationStatus.Text = "Failed to insert record (rows=" + nrows + ")!";
            Label_OperationStatus.BackColor = Color.Red;
        }
        Debug.Print("inserted: rows=" + nrows);
    }
}