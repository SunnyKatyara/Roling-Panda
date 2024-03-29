#include <SimpleIkController.h>

XBot::Cartesian::SimpleIk::SimpleIk(XBot::ModelInterface::Ptr model): 
    CartesianInterfaceImpl(model, get_task_list(*model))
{
    _opensot = boost::make_shared<OpenSoT::IKProblem>(model, 0.01);
}

bool XBot::Cartesian::SimpleIk::update(double time, double period)
{
    XBot::Cartesian::CartesianInterfaceImpl::update(time, period);
    
    _model->getJointPosition(_q);
    
    Eigen::Affine3d Tref;
    
    
    if(getReferencePosture(_posture_ref))
    {
        _opensot->_posture->setReference(_posture_ref);
    }
    
    _opensot->update(_q, false);
    if(!_opensot->solve(_dq))
    {
        return false;
    }
    
    _model->setJointVelocity(_dq/period);
    
    return true;
}

bool XBot::Cartesian::SimpleIk::setBaseLink(const std::string& ee_name, const std::string& new_base_link)
{
    if(!XBot::Cartesian::CartesianInterfaceImpl::setBaseLink(ee_name, new_base_link))
    {
        return false;
    }
    
    
    XBot::Logger::error("SimpleIk::setBaseLink unable to change base link \n");
    return false;
}

XBot::Cartesian::ProblemDescription XBot::Cartesian::SimpleIk::get_task_list(const ModelInterface& model)
{
    
    auto postural = MakePostural(model.getJointNum());
    
    XBot::Cartesian::ProblemDescription desc(postural);
    
    return desc;
}


extern "C" XBot::Cartesian::CartesianInterface* create_instance(XBot::ModelInterface::Ptr model,
                                                                XBot::Cartesian::ProblemDescription pb)
{
    return new XBot::Cartesian::SimpleIk(model);
}

extern "C" void destroy_instance( XBot::Cartesian::CartesianInterface* instance )
{
    delete instance;
}

