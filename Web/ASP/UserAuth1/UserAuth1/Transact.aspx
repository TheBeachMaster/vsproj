<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Transact.aspx.cs" Inherits="UserAuth1.Transact" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Goods Page</title>
    <link href="Contents/bootstrap-theme.min.css" rel="stylesheet" />
    <link href="Contents/bootstrap.min.css" rel="stylesheet" />
    <script src="Scripts/bootstrap.js"></script>
    <script src="Scripts/bootstrap.min.js"></script>
    <script src="Scripts/jQuery.js"></script>
    <script src="Scripts/npm.js"></script>
</head>
<body>
    <form id="form1" runat="server">
        <div class="container">
            <asp:CheckBoxList ID="ItemsList" runat="server">

            </asp:CheckBoxList>
        </div>
        <div class="container btn-group-justified">
            <asp:Button Text="Check Total" runat="server" CssClass="btn btn-lg btn-info" />
            <asp:Button Text="Pay Items" runat="server" CssClass="btn btn-lg btn-primary" OnClick="LaunchPayModal" />
        </div>


    </form>
    <!-- Bootstrap Modal Dialog -->
<div class="modal fade" id="transactModal" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <asp:UpdatePanel ID="upModal" runat="server" ChildrenAsTriggers="false" UpdateMode="Conditional">
            <ContentTemplate>
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
                        <h4 class="modal-title"><asp:Label ID="lblModalTitle" runat="server" Text=""></asp:Label></h4>
                    </div>
                    <div class="modal-body">
                        <asp:Label ID="lblModalBody" runat="server" Text=""></asp:Label>
                    </div>
                    <div class="modal-footer">
                        <button class="btn btn-info" data-dismiss="modal" aria-hidden="true">Close</button>
                    </div>
                </div>
            </ContentTemplate>
        </asp:UpdatePanel>
    </div>
</div

</body>
</html>
