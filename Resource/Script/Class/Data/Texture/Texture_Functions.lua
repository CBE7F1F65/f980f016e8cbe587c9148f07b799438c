function Texture:Init(tablefilename)
	if tablefilename == nil or tablefilename == "" then
		return;
	end
	local tabledata = {};
	local linecount;
	
	tabledata, linecount = tablefile:GetTableFileData(tablefilename, "nss");
	local texindex;
	for i=1, linecount do
		texindex = tabledata[1][i];
		self.filename[texindex] = tabledata[3][i];
		self.tex[texindex] = hge.Texture_Load(self.filename[texindex]);
		luastate.SetConst(tabledata[2][i], self.tex[texindex]);
	end
end