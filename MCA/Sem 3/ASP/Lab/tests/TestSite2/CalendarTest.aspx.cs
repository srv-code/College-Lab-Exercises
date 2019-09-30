using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Collections;
using System.Drawing;
using System.Diagnostics;

public partial class CalendarTest : System.Web.UI.Page {
	Hashtable scheduleddata;

	protected void Page_Load(object sender, EventArgs e) {
		string loadString = string.Format("[Load@{0}]", DateTime.Now.Millisecond);
		Page.Response.Write(loadString);
		Debug.Print("[{0}]", loadString);
		//Page.Validate();
		Debug.Print("Page: IsPostBack={0}", 
			Page.IsPostBack);

		if (IsPostBack)
			Response.Write("<h1>Data submitted successfully</h1>");
 
		scheduleddata = Get_schedule();
		Calendar1.Caption = "Exam schedule";
		Calendar1.NextPrevFormat = NextPrevFormat.ShortMonth;
		Calendar1.FirstDayOfWeek = FirstDayOfWeek.Sunday;
		Calendar1.TitleFormat = TitleFormat.MonthYear;
		Calendar1.ShowGridLines = true;
		Calendar1.DayStyle.Height = new Unit(50);
		Calendar1.DayStyle.Width = new Unit(70);
		Calendar1.OtherMonthDayStyle.BackColor = Color.BurlyWood;
		// Calendar1.TodaysDate = new DateTime(2014, 8, 9);
		Calendar1.TodayDayStyle.BackColor = Color.Aqua;
		Calendar1.VisibleDate = Calendar1.TodaysDate;
	}

	private Hashtable Get_schedule() {
		Hashtable schedule1 = new Hashtable();
		schedule1["8/10/2014"] = "First Internal Test";
		schedule1["9/23/2014"] = "Second Internal Test";
		schedule1["11/10/2014"] = "Semester exam";
		return schedule1;
	}

	protected void calender1_SelectionChanged(object sender, EventArgs e) {
		Label1.Text = "<h1> Selection changed to: " +
			 Calendar1.SelectedDate.ToShortDateString() + " </h1><br/>";
	}

	protected void Calendar1_VisibleMonthChanged(object sender, MonthChangedEventArgs me) {
		Label1.Text = "<h1> Month changed to :" + me.NewDate.ToShortDateString() + " </h1>";
	}

	protected void Calendar1_DayRender(object sender, DayRenderEventArgs de) {
		renderDate2(de);
	}

	private void renderDate2(DayRenderEventArgs e) {
		e.Cell.VerticalAlign = VerticalAlign.Top;
		if (e.Day.DayNumberText == "25") {
			e.Cell.Controls.Add(new LiteralControl("<p>User Group Meeting!</p>"));
			e.Cell.BorderColor = System.Drawing.Color.Black;
			e.Cell.BorderWidth = 1;
			e.Cell.BorderStyle = BorderStyle.Solid;
			e.Cell.BackColor = System.Drawing.Color.LightGray;
		}
	}

	private void renderDate1(DayRenderEventArgs de) {
		Debug.Print("Day={0}, sch={1}",
			de.Day.Date.ToShortDateString(),
			scheduleddata[de.Day.Date.ToShortDateString()]);

		if (scheduleddata[de.Day.Date.ToShortDateString()] != null) {
			Label lbll = new Label();
			lbll.Text += "<br/> <br/>";
			lbll.Text += (string)scheduleddata[de.Day.Date.ToShortDateString()];
			de.Cell.Controls.Add(lbll);
		}
	}

	protected void TextBox1_TextChanged(object sender, EventArgs e) {
		Debug.Print("invoked: TextBox1_TextChanged");
		TextBox2.Text = TextBox1.Text;
	}

	protected void Button_Submit_Command(object sender, CommandEventArgs e) {
		
	}
	protected void Button_Submit_Click(object sender, EventArgs e) {
		const string serverUploadPath = "~/uploads/";
		Debug.Print("Page.IsValid={0}", Page.IsValid);
		HttpFileCollection files = Request.Files;
		for (int i = 0; i < files.Count; i++) {
			if (files[i].FileName.Equals("")) {
				Debug.Print("No file selected for uploader {0}, skipping...", i+1);
				continue;
			}
			string savePath = serverUploadPath + files[i].FileName;
			Debug.Print("saving file as {0}, of size {1} bytes...", savePath, files[i].ContentLength);
			files[i].SaveAs(Page.MapPath(savePath));
		}
	}
}