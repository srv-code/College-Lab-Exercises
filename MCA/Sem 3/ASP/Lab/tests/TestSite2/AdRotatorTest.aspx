<%@ Page Language="C#" AutoEventWireup="true" CodeFile="AdRotatorTest.aspx.cs" Inherits="AdRotatorTest" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
		<div>
			<div>Ad 2 with Keyword filter='G':</div>
			<asp:AdRotator ID="AdRotator1" runat="server" 
				AdvertisementFile="~/App_Data/ads/ads.xml" AlternateTextField="MyAdRotator_G" 
				KeywordFilter="G" />
		</div>
		<div>
			<div>Ad 2 with Keyword filter='F':</div>
			<asp:AdRotator ID="AdRotator2" runat="server" 
				AdvertisementFile="~/App_Data/ads/ads.xml" AlternateTextField="MyAdRotator_F" 
				KeywordFilter="F" />
		</div>

    </form>
</body>
</html>
