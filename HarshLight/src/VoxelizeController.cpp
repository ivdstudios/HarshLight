#include "VoxelizeController.h"
#include "ModelRenderer.h"
#include "Actor.h"

const char* VoxelizeController::s_VoxelDimName = "VoxelDim";

VoxelizeController::VoxelizeController(uint32_t dim)
    :Component(), m_VoxelDim(dim)
{ }

void VoxelizeController::Start()
{
    auto mats = m_Actor->GetRenderer<ModelRenderer>()->GetMaterial(RenderPass::kRegular);
#ifdef _DEBUG
    assert(mats.size() > 0);
#endif
    Material* voxel_mat = mats[0];
    if (voxel_mat)
        voxel_mat->SetVec2Param(s_VoxelDimName,
            glm::vec2(static_cast<float>(m_VoxelDim), static_cast<float>(m_VoxelDim)));
}

void VoxelizeController::SetVoxelDim(uint32_t dim)
{
    m_VoxelDim = dim;
}

uint32_t VoxelizeController::GetVoxelDim() const
{
    return m_VoxelDim;
}
