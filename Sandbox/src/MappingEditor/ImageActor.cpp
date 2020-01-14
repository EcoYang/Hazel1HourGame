#include "ImageActor.h"
 
#include <imgui/imgui.h>

#include <windows.h>  
#include <Commdlg.h>
#include <filesystem>

namespace FS = std::filesystem;

void ImageActor::OnRender()
{
	Actor::OnRender();

}

void ImageActor::OnImGuiRender()
{
	Actor::OnImGuiRender();
	 
	ImGui::Begin("Image File Path");
	if (ImGui::Button("Choose File")) 
	{
		m_FilePath = OpenFileName();

		FS::path FilePath(m_FilePath);
		FS::path FileName = FS::path(FilePath).filename();

		FS::path AssetFilePath = FS::path("assets/").concat(FileName.string());
		FS::copy(FileName, AssetFilePath);
	}
	ImGui::End();
}

std::string ImageActor::OpenFileName(wchar_t* Filter, HWND Owner)
{
	OPENFILENAME OFN;
	wchar_t FileName[MAX_PATH] = L"";
	ZeroMemory(&OFN, sizeof(OFN));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = Owner;
	OFN.lpstrFilter = Filter;
	OFN.lpstrFile = FileName;
	OFN.nMaxFile = MAX_PATH;
	OFN.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	OFN.lpstrDefExt = L"";
	std::string FileNameString;

	if (GetOpenFileName(&OFN))
	{
		std::wstring WFileName(FileName);
		FileNameString = std::string(WFileName.begin(), WFileName.end());
	}

	return FileNameString; 
}
