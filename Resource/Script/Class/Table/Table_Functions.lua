function Table:_GetCell(linestr, charformat, initpos)
	local startpos;
	local endpos;
	local substr;
	startpos, endpos = string.find(linestr, "[^\t]+\t", initpos)
	if startpos == nil then
		startpos, endpos = string.find(linestr, "[^\t]+", initpos);
		substr = string.sub(linestr, startpos, endpos);
	else
		substr = string.sub(linestr, startpos, endpos-1);
	end
	
	if charformat == "n" or charformat == "f" then
		substr = tonumber(substr);
	end
	if charformat == "x" then
		substr = tonumber(substr, 16);
	end
	
	return substr, endpos;
end

function Table:GetTableFileData(filename, strformat)
	
	local tabledata = {};
	
	if filename == nil then
		return nil;
	end
	
	filename = hge.Resource_MakePath(filename);
	local file = io.open(filename, "r");
	local linestr = file:read();
	local linecount = 0;
	
	strformat = string.lower(strformat);
	local ncol = string.len(strformat);
	
	for i=1, ncol do
		tabledata[i] = {};
	end
	
	local initpos;
	while true do
		linestr = file:read();
		if linestr == nil then
			break;
		end
		linecount = linecount + 1;
		initpos = 1;
		for i=1, ncol do
			tabledata[i][linecount], initpos = self:_GetCell(linestr, string.sub(strformat, i, i), initpos);
		end
	end
	
	file:close();
	
	return tabledata, linecount;
end