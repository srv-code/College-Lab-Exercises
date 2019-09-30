<%@ Page Language="C#" AutoEventWireup="true" CodeFile="MySchedule.aspx.cs" Inherits="MySchedule" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>My September schedule</title>
	<link rel="stylesheet" type="text/css" href="~/Styles/calendar.css" />
</head>
<body>
    <form id="form1" runat="server">
        <div>
			<h1>My September Schedule</h1>
            <asp:Calendar ID="Calendar_MySeptSchedule" runat="server" 
                ondayrender="Calendar_MySeptSchedule_DayRender" FirstDayOfWeek="Sunday" 
				ShowGridLines="True">
				<DayStyle CssClass="day" />
				<OtherMonthDayStyle CssClass="other_month_days" />
				<SelectedDayStyle CssClass="selected_day" />
            	<TodayDayStyle CssClass="today" />
            </asp:Calendar>
        </div>
    </form>
</body>
</html>
